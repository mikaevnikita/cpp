#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>


const int rowsCount = 10;//Количество строк в двумерном массиве или высота игрового поля
const int columnsCount = 15;//Количество столбцов или ширина игрового поля
const unsigned char smb_Hero = 2;//ASCII код персонажа
const unsigned char smb_Wall = 177;//Код стены
const unsigned char smb_Box = 254;//Код коробки
const unsigned char smb_Exit = 176;//Код символа выхода с уровня
const int green = 10;//Green
const int white = 15;//White
const int yellow = 14;//Yellow
const int red = 12;//Red
const unsigned char levelData0[rowsCount][columnsCount + 1] = {
	"#####2#########",
	"#  x   #  x  ##",
	"# x ### x  #  #",
	"#x x  x  ## x #",
	"# x    ##  #  #",
	"#######    # x#",
	"#   x   xx #x #",
	"#xxx # # x   ##",
	"#1 x #   x x  #",
	"###############" };//Инициализировали уровень, заполнили его заранее тк надо было чем то заполнить. 1-Место появления героя, 2-Выход ,#-Стена,x-Ящик

HANDLE consoleHandle = 0;//Дескриптор консоли
bool isGameActive = true;
unsigned char levelData[rowsCount][columnsCount];//Сюда будем подгружать уровень из levelData0 , попутно меняя символы на ASCII
int heroRow = 0;//Переменные отвечающие за местоположение героя. Строка в массиве.
int heroColumn = 0;//Столбец в массиве.

void SetupSystem() {
	srand(time(0));//Зерно генератору рандома
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//Задали макрос.
}

void Initialize() {
	//Проинициализируем массив leveldata с помощью заданного уровня leveldata0
	for (int r = 0; r < rowsCount; r++) {
		for (int c = 0; c < columnsCount; c++) {
			unsigned char symbol = levelData0[r][c];
			switch (symbol)
			{
			case '#':
			{
				levelData[r][c] = smb_Wall;//Стена
				break;
			}
			case '1':
			{
				levelData[r][c] = smb_Hero;//Персонаж
				heroRow = r;
				heroColumn = c;
				break;
			}
			case '2':
			{
				levelData[r][c] = smb_Exit;//Выход
				break;
			}
			case 'x':
			{
				levelData[r][c] = smb_Box;//Коробка
				break;
			}
			default:
			{
				levelData[r][c] = symbol;//Дефолтный блок(пробел если встретили оставляем так же)
				break;
			}
			}
		}
	}
}


void Render() {
	COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 0;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);//Отрисовка графики с помощью курсоров и хэндлов поверх старой.


	printf("\n\n\t");
	for (int r = 0; r < rowsCount; r++) {
		for (int c = 0; c < columnsCount; c++) {
			unsigned char symbol = levelData[r][c];
			switch (symbol) {
			case smb_Wall:
			{
				SetConsoleTextAttribute(consoleHandle, white);
				break;
			}
			case smb_Box:
			{
				SetConsoleTextAttribute(consoleHandle, yellow);
				break;
			}
			case smb_Hero:
			{
				SetConsoleTextAttribute(consoleHandle, green);
				break;
			}
			case smb_Exit:
			{
				SetConsoleTextAttribute(consoleHandle, red);
				break;
			}
			}
			printf("%c", symbol);
		}
		printf("\n\t");
	}
	SetConsoleTextAttribute(consoleHandle, white);
	printf("\n\n\t Use AWSD to move ");
	SetConsoleTextAttribute(consoleHandle, green);
	printf("Hero. ");
	SetConsoleTextAttribute(consoleHandle, white);
	printf("R - Restart level.");
}


void MoveHeroTo(int row, int column) {
	bool canMoveToCell = false;//Переменная для проверки может ли игрок перейти в ячейку или нет.
	unsigned char destinationCell = levelData[row][column];
	switch (destinationCell) {
		//Если пробельный символ(пустота) может передвигаться
	case ' ':
	{
		canMoveToCell = true;
		break;
	}
	//Если символ выхода
	case smb_Exit:
	{
		isGameActive = false;
		break;
	}
	//Если символ ящика
	case smb_Box:
	{
		int heroDirectionR = row - heroRow;//Определяем направление движения по строкам
		int heroDirectionC = column - heroColumn;//Определяем направление движения по столбцам.

		if (levelData[row + heroDirectionR][column + heroDirectionC] == ' ') {
			//Если пустота за коробкой
			canMoveToCell = true;//можно двигать
			levelData[row][column] == ' ';//Убираем ящик с предыдущей позиции.
			levelData[row + heroDirectionR][column + heroDirectionC] = smb_Box;//Ставим ящик на новую позицию.
		}

		break;
	}
	}
	if (canMoveToCell) {
		levelData[heroRow][heroColumn] = ' ';//Ставим на прежнее место игрока пустоту(пробел)
		heroRow = row;//Устанавливаем новые значения местоположения игроку
		heroColumn = column;
		levelData[heroRow][heroColumn] = smb_Hero;//Ставим игрока на место нового передвижения.
	}
}

void Update() {
	unsigned char inputChar = tolower(_getch());//Получаем хоткеи
	switch (inputChar)
	{
		//Вверх
	case 'w':
	{
		MoveHeroTo(heroRow - 1, heroColumn);
		break;
	}
	//Влево
	case 'a':
	{
		MoveHeroTo(heroRow, heroColumn - 1);
		break;
	}
	//Назад
	case 's':
	{
		MoveHeroTo(heroRow + 1, heroColumn);
		break;
	}
	//Вправо
	case 'd':
	{
		MoveHeroTo(heroRow, heroColumn + 1);
		break;
	}
	//Клавиша рестарта
	case 'r':
	{
		Initialize();
		break;
	}
	}
}


void Shutdown() {
	system("cls");
	printf("\n\tGAME OVER !");//Функция выхода
	_getch();
}

int main() {
	SetupSystem();//Иницилизируем стартовые настройки
	Initialize();
	while (isGameActive) {
		Render();
		Update();
	}//Пока переменная имеет значение true
	Shutdown();
	return 0;
}
