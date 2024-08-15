#### Cách Đảo Ngược Chuỗi Sử Dụng Stack
##### Tạo và Khởi Tạo Stack:

- Khởi tạo stack để lưu trữ các ký tự của chuỗi.
Đẩy Các Ký Tự vào Stack:

- Duyệt qua từng ký tự của chuỗi và đẩy chúng vào stack.
##### Lấy Các Ký Tự Từ Stack:

Khi các ký tự đã được đẩy vào stack, lấy từng ký tự từ đỉnh stack để tạo ra chuỗi đảo ngược.

Ví Dụ trong C:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Khai báo stack và chỉ số đỉnh
char stack[MAX];
int top = -1;

// Hàm kiểm tra stack có rỗng không
int isEmpty() {
    return top == -1;
}

// Hàm kiểm tra stack có đầy không
int isFull() {
    return top == MAX - 1;
}

// Hàm thêm ký tự vào stack
void push(char ch) {
    if (isFull()) {
        printf("Stack đầy. Không thể thêm ký tự %c\n", ch);
    } else {
        stack[++top] = ch;
    }
}

// Hàm lấy ký tự ra khỏi stack
char pop() {
    if (isEmpty()) {
        printf("Stack rỗng. Không thể thực hiện pop\n");
        return '\0';  // Trả về ký tự lỗi
    } else {
        return stack[top--];
    }
}

// Hàm đảo ngược chuỗi sử dụng stack
void reverseString(char* str) {
    int length = strlen(str);
    
    // Đẩy các ký tự vào stack
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }
    
    // Lấy các ký tự từ stack và xây dựng chuỗi đảo ngược
    for (int i = 0; i < length; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];
    
    // Nhập chuỗi từ người dùng
    printf("Nhập chuỗi: ");
    fgets(str, MAX, stdin);
    
    // Xóa ký tự newline ở cuối chuỗi nếu có
    str[strcspn(str, "\n")] = '\0';
    
    // Đảo ngược chuỗi
    reverseString(str);
    
    // Hiển thị chuỗi đảo ngược
    printf("Chuỗi đảo ngược: %s\n", str);
    
    return 0;
}
```
- Giải Thích Mã Lệnh:
    - `Khởi Tạo Stack`: stack là mảng dùng để lưu trữ các ký tự. top giữ chỉ số đỉnh của stack.
    - `push(char ch)`: Thêm ký tự ch vào đỉnh của stack. Kiểm tra xem stack đã đầy chưa trước khi thêm.
    - `pop()`: Lấy ký tự từ đỉnh stack và giảm chỉ số top. Kiểm tra xem stack có rỗng không trước khi lấy.
    - `reverseString(char* str)`: Đẩy tất cả các ký tự của chuỗi vào stack.
    Sau đó, lấy từng ký tự từ stack để xây dựng chuỗi đảo ngược.
    - `main()`: Nhập chuỗi từ người dùng và xóa ký tự newline nếu có.
    Gọi hàm `reverseString()` để đảo ngược chuỗi.
    Hiển thị chuỗi đảo ngược.