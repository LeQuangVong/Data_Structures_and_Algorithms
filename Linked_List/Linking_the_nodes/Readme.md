Liên kết các node trong C là quá trình kết nối các node với nhau để tạo thành một danh sách liên kết (Linked List). Việc này được thực hiện bằng cách sử dụng con trỏ (next) của mỗi node để trỏ đến node tiếp theo trong danh sách.

#### Ví dụ về việc liên kết các node
- Bước 1: Định nghĩa cấu trúc của Node
Trước tiên, bạn cần định nghĩa cấu trúc của một node, như đã đề cập trước đó:
```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;            // Dữ liệu của node
    struct Node* next;   // Con trỏ tới node tiếp theo
};
```
- Bước 2: Tạo các node
Tạo các node và liên kết chúng lại với nhau như sau:
```
int main() {
    // Tạo ba node riêng biệt
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Cấp phát bộ nhớ cho ba node trong heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Gán dữ liệu và liên kết các node
    head->data = 1;      // Gán dữ liệu cho node đầu tiên
    head->next = second; // Liên kết node đầu tiên với node thứ hai

    second->data = 2;    // Gán dữ liệu cho node thứ hai
    second->next = third; // Liên kết node thứ hai với node thứ ba

    third->data = 3;     // Gán dữ liệu cho node thứ ba
    third->next = NULL;  // Node cuối cùng, trỏ tới NULL

    // Duyệt danh sách và in ra các giá trị
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");

    return 0;
}
```
- Bước 3: Liên kết các `node`
Trong đoạn mã trên, các `node` được liên kết với nhau thông qua các bước sau:

    - Cấp phát bộ nhớ: Ba `node` (head, second, third) được cấp phát bộ nhớ bằng hàm malloc.
    - Gán dữ liệu: Mỗi `node` được gán một giá trị cho trường `data`.
    - Liên kết các `node`: Con trỏ `next` của mỗi `node` được gán giá trị là địa chỉ của `node tiếp theo`, trừ `node cuối cùng` có next trỏ tới `NULL`.