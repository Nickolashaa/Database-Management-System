#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#define _WIN32_WINNT 0x0A00


struct Rock {
	int number;
	char name[20];
	char color[20];
	int rare;
	int price;
};


void str(int n) {
	printf("%c", 204);
	for (int number = 0; number < n; ++number)
		printf("%c", 205);
	printf("%c\n", 186);
}


void str2() {
	printf("%c", 204);
	printf("%c", 205);
	printf("%c", 206);
	for (int number = 0; number < 10; ++number)
		printf("%c", 205);
	printf("%c", 206);
	for (int number = 0; number < 10; ++number)
		printf("%c", 205);
	printf("%c", 206);
	for (int number = 0; number < 5; ++number)
		printf("%c", 205);
	printf("%c", 206);
	for (int number = 0; number < 5; ++number)
		printf("%c", 205);
	printf("%c\n", 186);
}


void up(int n) {
	printf("%c", 201);
	for (int number = 0; number < n; ++number)
		printf("%c", 205);
	printf("%c", 187);
}


void up2(int n) {
	printf("%c", 201);
	for (int number = 0; number < n; ++number)
		if (number == 1 or number == 12 or number == 23 or number == 29)
			printf("%c", 203);
		else
			printf("%c", 205);
	printf("%c", 187);
}


void down(int n) {
	printf("%c", 200);
	for (int number = 0; number < n; ++number)
		printf("%c", 205);
	printf("%c\n", 188);
}


void down2(int n) {
	printf("%c", 200);
	for (int number = 0; number < n; ++number)
		if (number == 1 or number == 12 or number == 23 or number == 29)
			printf("%c", 202);
		else
			printf("%c", 205);
	printf("%c", 188);
}


void Vvod(Rock data[10]) {
	system("cls");
	for (int i = 0; i < 10; ++i)
		data[i].number = 0;
	printf("\nVvod\n");
	int flag = 1, cnt;
	char cnt_s[10];
	while (flag) {
		printf("Enter the number of lines\n");
		scanf_s("%s", &cnt_s, 10);
		for (int i = 0; i < strlen(cnt_s); ++i) {
			if (isdigit(cnt_s[i]) == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("Invalid data type, try again...\n");
			flag = 1;
		}
		else {
			cnt = atoi(cnt_s);
			break;
		}
	}
	for (int i = 0; i < cnt; ++i) {
		Rock item;
		item.number = i + 1;
		flag = 1;
		printf("\n#%d\n", item.number);
		while (flag) {
			printf("Enter the name (Letters) - ");
			scanf_s("%s", &item.name, 20);
			for (int i = 0; i < strlen(item.name); ++i) {
				if (isalpha(item.name[i]) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				printf("Invalid data type, try again...\n");
				flag = 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		while (flag) {
			printf("\nEnter the color (Letters) - ");
			scanf_s("%s", &item.color, 20);
			for (int i = 0; i < strlen(item.color); ++i) {
				if (isalpha(item.color[i]) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				printf("Invalid data type, try again...\n");
				flag = 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		while (flag) {
			printf("\nEnter the rare % (Number 0 - 100) - ");
			char rare[20];
			scanf_s("%s", &rare, 20);
			for (int i = 0; i < strlen(rare); ++i) {
				if (isdigit(rare[i]) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				printf("Invalid data type, try again...\n");
				flag = 1;
			}
			else {
				item.rare = atoi(rare);
				flag = 1;
				break;
			}
		}
		while (flag) {
			printf("\nEnter the price (Number < 100000) - ");
			char price[20];
			scanf_s("%s", &price, 20);
			for (int i = 0; i < strlen(price); ++i) {
				if (isdigit(price[i]) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				printf("Invalid data type, try again...\n");
				flag = 1;
			}
			else {
				item.price = atoi(price);
				flag = 1;
				break;
			}
		}
		data[i] = item;
	}
	FILE* write = fopen("Base.dat", "wb");
	fwrite(data, sizeof(Rock), 10, write);
	fclose(write);
	printf("Succesfully!");
	Sleep(500);
	system("cls");
}


void Vivod(Rock data[10]) {
	while (true) {
		system("cls");
		HWND hwnd = GetConsoleWindow();
		LPPOINT pPnt;
		pPnt = static_cast<LPPOINT>(malloc(sizeof(*pPnt)));
		GetCursorPos(pPnt);
		int flag = 2, cnt = 0;
		up(16);
		printf("\n");
		printf("%cOutput          %c\n", 186, 186);
		str(16);
		printf("%c1 - Current Base%c\n", 186, 186);
		str(16);
		printf("%c2 - Saved Base  %c\n", 186, 186);
		down(16);
		Sleep(200);
		if ((pPnt->x > 14 && pPnt->x < 164) && (pPnt->y > 102 && pPnt->y < 131) && (GetKeyState(VK_LBUTTON) < 0))
			flag = 1;
		if ((pPnt->x > 14 && pPnt->x < 164) && (pPnt->y > 139 && pPnt->y < 168) && (GetKeyState(VK_LBUTTON) < 0))
			flag = 0;
		if (flag == 1) {
			system("cls");
			flag = 0;
			int k = 1;
			for (int i = 0; i < 10; ++i) {
				if (data[i].number > 0) {
					data[i].number = k;
					k += 1;
				}
			}
			up2(35);
			printf("\n%cN%cName      %cColor     %cRare %cPrice%c\n", 186, 186, 186, 186, 186, 185);
			str2();
			for (int i = 0; i < 10; ++i) {
				if (data[i].number > 0) {
					printf("%c%d%c", 186, data[i].number, 186);
					printf("%-10s%c", data[i].name, 186);
					printf("%-10s%c", data[i].color, 186);
					printf("%-5d%c", data[i].rare, 186);
					printf("%-5d%c\n", data[i].price, 186);
					if (i != 9)
						if (data[i + 1].number > 0)
							str2();
					flag = 1;
					cnt += 1;
				}
			}
			if (flag == 0) {
				down2(35);
				printf("\nThe database is empty\n");
				system("Pause");
			}
			else {
				down2(35);
				printf("\n");
				system("pause");
				break;
			}
		}
		else if (flag == 0) {
			system("cls");
			Rock Curr[10];
			FILE* read = fopen("Base.dat", "rb");
			fread(Curr, sizeof(Rock), 10, read);
			fclose(read);
			flag = 0;
			up2(35);
			printf("\n%cN%cName      %cColor     %cRare %cPrice%c\n", 186, 186, 186, 186, 186, 185);
			str2();
			int k = 1;
			for (int i = 0; i < 10; ++i) {
				if (Curr[i].number > 0) {
					Curr[i].number = k;
					k += 1;
				}
			}
			for (int i = 0; i < 10; ++i) {
				if (Curr[i].number > 0) {
					printf("%c%d%c", 186, Curr[i].number, 186);
					printf("%-10s%c", Curr[i].name, 186);
					printf("%-10s%c", Curr[i].color, 186);
					printf("%-5d%c", Curr[i].rare, 186);
					printf("%-5d%c\n", Curr[i].price, 186);
					if (i != 9)
						if (Curr[i + 1].number > 0)
							str2();
					flag = 1;
					cnt += 1;
				}
			}
			if (flag == 0) {
				down2(35);
				printf("\nThe database is empty\n");
			}
			else {
				down2(35);
				printf("\n");
			}
			printf("\n");
			system("pause");
			break;
		}
		Sleep(250);
	}
}


void Add(Rock data[10]) {
	system("cls");
	Rock item;
	int flag = 1, cnt = 0;
	printf("\nAdd\n");
	while (flag){
		printf("Enter the name (Letters) - ");
		scanf_s("%s", &item.name, 20);
		for (int i = 0; i < strlen(item.name); ++i) {
			if (isalpha(item.name[i]) == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("Invalid data type, try again...\n");
			flag = 1;
		}
		else {
			flag = 1;
			break;
		}
	}
	while (flag) {
		printf("\nEnter the color (Letters) - ");
		scanf_s("%s", &item.color, 20);
		for (int i = 0; i < strlen(item.color); ++i) {
			if (isalpha(item.color[i]) == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("Invalid data type, try again...\n");
			flag = 1;
		}
		else {
			flag = 1;
			break;
		}
	}
	while (flag) {
		printf("\nEnter the rare % (Number 0 - 100) - ");
		char rare[20];
		scanf_s("%s", &rare, 20);
		for (int i = 0; i < strlen(rare); ++i) {
			if (isdigit(rare[i]) == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("Invalid data type, try again...\n");
			flag = 1;
		}
		else {
			item.rare = atoi(rare);
			flag = 1;
			break;
		}
	}
	while (flag) {
		printf("\nEnter the price (Number < 100000) - ");
		char price[20];
		scanf_s("%s", &price, 20);
		for (int i = 0; i < strlen(price); ++i) {
			if (isdigit(price[i]) == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("Invalid data type, try again...\n");
			flag = 1;
		}
		else {
			item.price = atoi(price);
			flag = 1;
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (data[i].number > 0)
			cnt += 1;
		}
	item.number = cnt + 1;
	if ((cnt + 1) < 11)
		data[cnt] = item;
	else
		printf("\nError, the free memory of the database is over\n");
	printf("Successfuly!\n");
	Sleep(500);
}


void Delete(Rock data[10]) {
	system("cls");
	printf("\nDelete\n");
	printf("Enter the row number of the database that you want to delete (Number)\n");
	int flag = 1, flag2 = 0;
	char num[2];
	scanf_s("%s", &num, 2);
	if (isdigit(num[0]) == 0) {
		printf("Invalid data type, try again...\n");
		scanf_s("%s", &num, 2);
	}
	flag = 0;
	for (int i = 0; i < 10; ++i) {
		if (i + 1 == atoi(num)) {
			flag = 1;
			flag2 = 1;
			data[i].number = 0;
			continue;
		}
		if (flag == 1) {
			data[i].number -= 1;
		}
	}
	if (flag2)
		printf("Successfuly\n");
	else
		printf("There is no row with this number in the database\n");
	Sleep(500);
}



void Delete_num(Rock data[10], int num[10]) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (data[j].number > 0) {
				if (data[j].number == num[i]) {
					data[j].number = 0;
					break;
				}
			}
		}
	}
}

int __eq__(char a[20], char b[20]) {
	if (strlen(a) != strlen(b))
		return 0;
	for (int i = 0; i < 20; ++i) {
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}


void Search(Rock data[10]) {
	system("cls");
	char word[20];
	int flag = 1, num;
	char k[5];
	printf("\Search\n1 - Search on base\n2 - Search && Delete\n");
	while (flag) {
		scanf_s("%s", &k, 5);
		for (int i = 0; i < strlen(k); ++i) {
			if (isdigit(k[i]) == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("Invalid data type, try again...\n");
			flag = 1;
		}
		else {
			num = atoi(k);
			break;
		}
	}
	flag = 0;
	if (num == 1) {
		printf("Enter a word to search the database\n");
		scanf_s("%s", &word, 20);
		for (int i = 0; i < 10; ++i) {
			if (data[i].number > 0) {
				if (__eq__(word, data[i].name)) {
					printf("Found a match at string %d: Object`s Name - %s\n", i + 1, data[i].name);
					flag = 1;
				}
				if (__eq__(word, data[i].color)) {
					printf("Found a match at string %d: %s`s color - %s\n", i + 1, data[i].name, data[i].color);
					flag = 1;
				}
				if (isdigit(word[0]) != 0) {
					if (atoi(word) == data[i].rare) {
						printf("Found a match at string %d: %s`s rare - %d\n", i + 1, data[i].name, data[i].rare);
						flag = 1;
					}
					if (atoi(word) == data[i].price) {
						printf("Found a match at string %d: %s`s price - %d\n", i + 1, data[i].name, data[i].price);
						flag = 1;
					}
				}
			}
		}
		if (flag == 0)
			printf("Nothing found\n");
		system("Pause");
	}
	else {
		printf("Enter a word to search && delete the database\n");
		scanf_s("%s", &word, 20);
		int black_list[10], k = 0;
		for (int i = 0; i < 10; ++i) {
			if (data[i].number > 0) {
				if (__eq__(word, data[i].name)) {
					printf("Found a match at string %d: Object`s Name - %s\n", i + 1, data[i].name);
					black_list[k] = data[i].number;
					k += 1;
					flag = 1;
				}
				if (__eq__(word, data[i].color)) {
					printf("Found a match at string %d: %s`s color - %s\n", i + 1, data[i].name, data[i].color);
					black_list[k] = data[i].number;
					k += 1;
					flag = 1;
				}
				if (isdigit(word[0]) != 0) {
					if (atoi(word) == data[i].rare) {
						printf("Found a match at string %d: %s`s rare - %d\n", i + 1, data[i].name, data[i].rare);
						black_list[k] = data[i].number;
						k += 1;
						flag = 1;
					}
					if (atoi(word) == data[i].price) {
						printf("Found a match at string %d: %s`s price - %d\n", i + 1, data[i].name, data[i].price);
						black_list[k] = data[i].number;
						k += 1;
						flag = 1;
					}
				}
			}
		}
		Delete_num(data, black_list);
		printf("Complete!\n");
		if (flag == 0)
			printf("Nothing found\n");
		system("Pause");
	}
}


void Name_sort(Rock data[10]) {
	Rock c;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if ((data[i].number != 0) && (data[j].number != 0)) {
				if (_stricmp(data[i].name, data[j].name) > 0) {
					c = data[i];
					data[i] = data[j];
					data[j] = c;
				}
			}
		}
	}
	printf("\nSort Completed\n");
}


void Color_sort(Rock data[10]) {
	Rock c;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if ((data[i].number != 0) && (data[j].number != 0)) {
				if (_stricmp(data[i].color, data[j].color) > 0) {
					c = data[i];
					data[i] = data[j];
					data[j] = c;
				}
			}
		}
	}
	printf("\nSort Completed\n");
}


void Rare_up_sort(Rock data[10]) {
	Rock c;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if ((data[i].number != 0) && (data[j].number != 0)) {
				if (data[i].rare > data[j].rare) {
					c = data[i];
					data[i] = data[j];
					data[j] = c;
				}
			}
		}
	}
	printf("\nSort Completed\n");
}


void Rare_down_sort(Rock data[10]) {
	Rock c;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if ((data[i].number != 0) && (data[j].number != 0)) {
				if (data[i].rare < data[j].rare) {
					c = data[i];
					data[i] = data[j];
					data[j] = c;
				}
			}
		}
	}
	printf("\nSort Completed\n");
}


void Price_up_sort(Rock data[10]) {
	Rock c;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if ((data[i].number != 0) && (data[j].number != 0)) {
				if (data[i].price > data[j].price) {
					c = data[i];
					data[i] = data[j];
					data[j] = c;
				}
			}
		}
	}
	printf("\nSort Completed\n");
}


void Price_down_sort(Rock data[10]) {
	Rock c;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if ((data[i].number != 0) && (data[j].number != 0)) {
				if (data[i].price < data[j].price) {
					c = data[i];
					data[i] = data[j];
					data[j] = c;
				}
			}
		}
	}
	printf("\nSort Completed\n");
}


void Sort(Rock data[10]) {
	HWND hwnd = GetConsoleWindow();
	LPPOINT pPnt;
	pPnt = static_cast<LPPOINT>(malloc(sizeof(*pPnt)));
	while (true) {
		GetCursorPos(pPnt);
		system("cls");
		up(14);
		printf("\n%cSearch        %c\n", 186, 186);
		str(14);
		printf("%c1 - Name      %c\n", 186, 186);
		str(14);
		printf("%c2 - Color     %c\n", 186, 186);
		str(14);
		printf("%c3 - Rare Up   %c\n", 186, 186);
		str(14);
		printf("%c4 - Rare Down %c\n", 186, 186);
		str(14);
		printf("%c5 - Price Up  %c\n", 186, 186);
		str(14);
		printf("%c6 - Price Down%c\n", 186, 186);
		down(14);
		printf("\n");
		Sleep(200);
		if ((pPnt->x > 14 && pPnt->x < 144) && (pPnt->y > 101 && pPnt->y < 134) && (GetKeyState(VK_LBUTTON) < 0)) {
			Name_sort(data);
			Sleep(250);
			break;
		}
		if ((pPnt->x > 14 && pPnt->x < 144) && (pPnt->y > 136 && pPnt->y < 171) && (GetKeyState(VK_LBUTTON) < 0)){
			Color_sort(data);
			Name_sort(data);
			Sleep(250);
			break;
		}
		if ((pPnt->x > 14 && pPnt->x < 144) && (pPnt->y > 175 && pPnt->y < 210) && (GetKeyState(VK_LBUTTON) < 0)){
			Rare_up_sort(data);	
			Name_sort(data);
			Sleep(250);
			break;
		}
		if ((pPnt->x > 14 && pPnt->x < 144) && (pPnt->y > 215 && pPnt->y < 250) && (GetKeyState(VK_LBUTTON) < 0)){
			Rare_down_sort(data);
			Name_sort(data);
			Sleep(250);
			break;
		}
		if ((pPnt->x > 14 && pPnt->x < 144) && (pPnt->y > 252 && pPnt->y < 288) && (GetKeyState(VK_LBUTTON) < 0)){
			Price_up_sort(data);
			Name_sort(data);
			Sleep(250);
			break;
		}
		if ((pPnt->x > 14 && pPnt->x < 144) && (pPnt->y > 291 && pPnt->y < 323) && (GetKeyState(VK_LBUTTON) < 0)){
			Price_down_sort(data);
			Name_sort(data);
			Sleep(250);
			break;
		}
		Sleep(250);
	}
}


void Save(Rock data[10]) {
	system("cls");
	FILE* write = fopen("base.dat", "wb");
	fwrite(data, sizeof(Rock), 10, write);
	fclose(write);
	printf("Successfuly!\n");
	int flag = 0;
	up2(35);
	printf("\n%cN%cName      %cColor     %cRare %cPrice%c\n", 186, 186, 186, 186, 186, 185);
	str2();
	for (int i = 0; i < 10; ++i) {
		if (data[i].number > 0) {
			printf("%c%d%c", 186, data[i].number, 186);
			printf("%-10s%c", data[i].name, 186);
			printf("%-10s%c", data[i].color, 186);
			printf("%-5d%c", data[i].rare, 186);
			printf("%-5d%c\n", data[i].price, 186);
			if (i != 9)
				if (data[i + 1].number > 0)
					str2();
			flag = 1;
		}
	}
	if (flag == 0) {
		down2(35);
		printf("\nThe database is empty\n");
	}
	else {
		down2(35);
		printf("\n");
	}
	system("Pause");
}


void Exit() {
	system("cls");
	for (int i = 0; i < 40; ++i) {
		printf(" O   O   O  \n");
		printf("/|\\ /|\\ /|\\\n");
		printf("/ \\ / \\ / \\\n");
		printf("Thanks for your attention!\n");
		Sleep(250);
		system("cls");
		printf("\\O/ \\O/ \\O/ \n");
		printf(" |   |   |\n");
		printf("/ \\ / \\ / \\\n");
		printf("Thanks for your attention!\n");
		Sleep(250);
		system("cls");
	}
	system("Exit");
}


int main() {
	system("color a");


	HWND hwnd = GetConsoleWindow();
	LPPOINT pPnt;
	pPnt = static_cast<LPPOINT>(malloc(sizeof(*pPnt)));


	Rock FILE_data[10];
	Rock data[10] = { 0, ' ', ' ', 0, 0 };
	FILE* read = fopen("Base.dat", "rb");
	fread(FILE_data, sizeof(Rock), 10, read);
	fclose(read);


	int i = 0;
	for (int number = 0; number < 10; ++number) {
		if (FILE_data[number].number > 0) {
			data[i] = FILE_data[number];
			i += 1;
		}
	}


	while (true) {
		system("cls");
		up(10);
		printf("\n%cMENU (*_*)%c\n", 186, 186);
		str(10);
		printf("%c1 - Input %c\n", 186, 186);
		str(10);
		printf("%c2 - Output%c\n", 186, 186);
		str(10);
		printf("%c3 - Add   %c\n", 186, 186);
		str(10);
		printf("%c4 - Search%c\n", 186, 186);
		str(10);
		printf("%c5 - Delete%c\n", 186, 186);
		str(10);
		printf("%c6 - Sort  %c\n", 186, 186);
		str(10);
		printf("%c7 - Save  %c\n", 186, 186);
		str(10);
		printf("%c8 - Exit  %c\n", 186, 186);
		down(10);
		GetCursorPos(pPnt);
		ScreenToClient(hwnd, pPnt);
		Sleep(250);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 68 && pPnt->y < 103) && (GetKeyState(VK_LBUTTON) < 0))
			Vvod(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 108 && pPnt->y < 140) && (GetKeyState(VK_LBUTTON) < 0))
			Vivod(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 145 && pPnt->y < 179) && (GetKeyState(VK_LBUTTON) < 0))
			Add(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 184 && pPnt->y < 215) && (GetKeyState(VK_LBUTTON) < 0))
			Search(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 222 && pPnt->y < 254) && (GetKeyState(VK_LBUTTON) < 0))
			Delete(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 259 && pPnt->y < 292) && (GetKeyState(VK_LBUTTON) < 0))
			Sort(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 299 && pPnt->y < 329) && (GetKeyState(VK_LBUTTON) < 0))
			Save(data);
		if ((pPnt->x > 7 && pPnt->x < 101) && (pPnt->y > 337 && pPnt->y < 369) && (GetKeyState(VK_LBUTTON) < 0))
			Exit();
	}
}