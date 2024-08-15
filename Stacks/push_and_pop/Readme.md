Thao Tác Push và Pop trong Stack
Push và Pop là hai thao tác cơ bản trong cấu trúc dữ liệu stack (ngăn xếp). Đây là các thao tác chính để thêm và loại bỏ phần tử trong stack, tuân theo nguyên tắc LIFO (Last In, First Out).

#### Push (Thêm Phần Tử)
Push là thao tác thêm một phần tử vào đỉnh của stack. Khi thực hiện thao tác này, phần tử mới sẽ được đặt lên trên phần tử hiện tại ở đỉnh stack, và chỉ số đỉnh (top) sẽ được cập nhật để chỉ đến phần tử mới.

Cú pháp:
```
void push(int value);
```
Ví dụ trong C:
```
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;  // Khởi tạo stack rỗng

int isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack đầy. Không thể thêm phần tử %d\n", value);
    } else {
        stack[++top] = value;  // Tăng chỉ số đỉnh và thêm phần tử
        printf("Đã thêm phần tử %d vào stack\n", value);
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    return 0;
}
```
- Giải thích:

    - ```top```: Chỉ số đỉnh của stack. Ban đầu là -1, nghĩa là stack rỗng.
    - ```isFull()```: Kiểm tra xem stack đã đầy chưa.
    - ```push(int value)```: Nếu stack chưa đầy, tăng chỉ số top lên 1 và gán giá trị phần tử vào stack[top].
#### Pop (Lấy Phần Tử)
Pop là thao tác lấy và loại bỏ phần tử ở đỉnh của stack. Sau khi phần tử được lấy ra, chỉ số đỉnh (top) sẽ được cập nhật để chỉ đến phần tử trước đó.

Cú pháp:
```
int pop();
Ví dụ trong C:

c
Copy code
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;  // Khởi tạo stack rỗng

int isEmpty() {
    return top == -1;
}

int pop() {
    if (isEmpty()) {
        printf("Stack rỗng. Không thể thực hiện pop\n");
        return -1;  // Trả về giá trị lỗi
    } else {
        return stack[top--];  // Trả về phần tử và giảm chỉ số đỉnh
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Lấy phần tử ra khỏi stack: %d\n", pop());
    printf("Lấy phần tử ra khỏi stack: %d\n", pop());
    return 0;
}
```
- Giải thích:

    - isEmpty(): Kiểm tra xem stack có rỗng không.
    - pop(): Nếu stack không rỗng, trả về phần tử ở đỉnh và giảm chỉ số top xuống 1.
    