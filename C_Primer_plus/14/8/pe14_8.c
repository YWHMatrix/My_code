#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct airplane {

  int number;
  bool seat;
  char surname[10];
  char names[10];
};

void show_menu();
char get_char();
void choose_menu(char ch, struct airplane airplanes[]);
void sort_names(int temp[], int, struct airplane airplanes[]);
struct airplane choose_seat(bool b_serat, struct airplane airplanes[]);

int main(int argc, char *argv[]) {

  // struct airplane airplanes[12] = {{1, true, "zhang", "shan"},
  //                                  {2, true, "li", "shi"},
  //                                  {3, true, "li", "hua"},
  //                                  {4, true, "a", "hua"}};
  struct airplane airplanes[12];

  for (int i = 0; i < 12; i++) {
    airplanes[i].number = i + 1;
    airplanes[i].seat = false;
  }

  int ch;
  while (1) {
    show_menu();
    ch = get_char();
    if (ch == 'f') {
      break;
    }
    choose_menu(ch, airplanes);
  }

  return 0;
}

void show_menu() {
  printf("To choose a function ,enter its letter label\n");
  puts("a)show number of empty seats");      //显示空座位数
  puts("b)Showlistofemptyseats");            // 显示空座位列表
  puts("c)Show alphabetical list of seats"); // 显示按字母排列的桌位表
  puts("d)Assign a customer to a seat assignment"); // 将客户分配给座位分配
  puts("e)Delete a seat assignment");               // 删除座位分配
  puts("f)Quit");
}

char get_char() {
  char ch;
  int i = 0;
  do {
    if (i != 0) {
      puts("请输入a~f:");
    }
    i++;
    ch = getchar();
    while (getchar() != '\n') {
      continue;
    }
  } while (ch < 'a' || ch > 'f');
  return ch;
}

void choose_menu(char ch, struct airplane airplanes[]) {
  int count = 0;
  int temp[12] = {0};
  switch (ch) {
    int j = 0;
  case 'a': //显示空座位数量
    for (size_t i = 0; i < 12; i++) {
      if (airplanes[i].seat == false) {
        count++;
      }
    }
    printf("还有座位数：");
    printf("%d\n", count);
    break;
  case 'b': //显示空座位列表
    puts("空座位列表：");
    for (int i = 0; i < 12; i++) {
      if (airplanes[i].seat == false) {
        printf("座位号码:%d\n", airplanes[i].number);
      }
    }
    break;
  case 'c': //按照座位字母顺序排列座位
    for (int i = 0; i < 12; i++) {
      if (airplanes[i].seat == true) {
        temp[j] = i;
        j++;
      }
    }
    sort_names(temp, j, airplanes);
    break;
  case 'd': // 分配座位
    choose_seat(true, airplanes);
    break;
  }
}

void sort_names(int temp[], int j, struct airplane airplanes[]) {
  int t;
  for (size_t i = 0; i < j; i++) {
    for (size_t k = 0; k < j - 1; k++) {
      if (memcmp(airplanes[temp[k]].surname, airplanes[temp[k + 1]].surname,
                 1) > 0) {
        t = temp[k + 1];
        temp[k + 1] = temp[k];
        temp[k] = t;
      }
    }
    for (int i = 0; i < j; i++) {
      printf("%s %s , seat : %d \n", airplanes[i].surname, airplanes[i].names,
             temp[i]);
    }
  }
}

struct airplane choose_seat(bool b_serat,struct airplane airplanes[]) { //选择座位
  int num;
  while (1) {
    printf("请输入你选择的座位号(1~12):");
    scanf("%d", &num);
    while (getchar() != '\n') {
      continue;
    }
    if (num <= 0 || num > 12) {
      continue;
    }
    if (b_serat == airplanes[num - 1].seat) {
      break;
    }
    if(b_serat == true)
    {
      puts("空座位不能被删除");
    }
    if(b_serat == false)
    {
      puts("这个座位已经有乘客了");
    }
  }
  if (b_serat == false) { //分配座位
    airplanes[num-1].seat = true;
    printf("请输入你的姓:");
    scanf("%10s",airplanes[num-1].surname);
    printf("请输入你的名:");
    scanf("%10s",airplanes[num-1].names);
  }else {
    airplanes[num-1].seat = false;
  }
  return *airplanes;
}
