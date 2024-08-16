Để chèn một node mới vào cuối của một Linked List trong C, bạn cần thực hiện các bước sau:

- Tạo một node mới: Cấp phát bộ nhớ cho node mới và gán dữ liệu cho nó.
- Duyệt đến node cuối cùng của Linked List: Sử dụng một con trỏ tạm thời để duyệt qua các node cho đến khi tìm thấy node có con trỏ next là NULL.
- Liên kết node cuối cùng với node mới: Trỏ con trỏ next của node cuối cùng tới node mới.
#### Ví dụ
Chèn một node vào cuối của Linked List:
```
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm chèn một node vào cuối danh sách
void insertAtEnd(struct Node** head_ref, int new_data) {
    // 1. Cấp phát bộ nhớ cho node mới
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // 2. Gán dữ liệu cho node mới
    new_node->data = new_data;
    new_node->next = NULL;

    // 3. Kiểm tra nếu danh sách trống, node mới sẽ là node đầu tiên
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // 4. Nếu danh sách không trống, duyệt tới node cuối cùng
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // 5. Liên kết node cuối cùng với node mới
    last->next = new_node;
}

// Hàm duyệt và in Linked List
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Khởi tạo Linked List rỗng
    struct Node* head = NULL;

    // Chèn các node vào cuối danh sách
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // In danh sách
    printList(head);

    return 0;
}
```
- Giải thích:
    - `insertAtEnd`: Hàm này thực hiện chèn một `node mới` vào cuối danh sách.

    - `struct Node**head_ref`: Là `tham chiếu` tới `con trỏ head` của danh sách.
    - `new_node->next = NULL;`: Vì đây là `node cuối cùng` trong danh sách, `con trỏ next` của `node` này sẽ `trỏ` tới `NULL`.
    - `Kiểm tra danh sách rỗng`: Nếu `danh sách trống` (head là NULL), `node mới` sẽ trở thành `node đầu tiên`.
    - Duyệt đến `node cuối cùng`: Nếu `danh sách không rỗng`, `con trỏ last` sẽ duyệt qua danh sách cho đến khi tìm thấy `node cuối cùng` (`node` có `con trỏ next` là `NULL`).
    - Liên kết `node cuối cùng` với `node mới`: Trỏ `con trỏ next` của `node cuối cùng` tới `node mới`.
    - `printList`: Hàm này duyệt qua các `node` trong danh sách và in giá trị của từng `node` ra màn hình.