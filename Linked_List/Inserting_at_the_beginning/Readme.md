Để chèn một node mới vào đầu của một Linked List trong C, thực hiện các bước sau:

- Tạo một node mới: Cấp phát bộ nhớ cho node mới và gán dữ liệu cho nó.
- Cập nhật con trỏ next của node mới: Trỏ con trỏ next của node mới tới node đầu tiên hiện tại của danh sách (tức là head).
- Cập nhật con trỏ head: Cập nhật con trỏ head để trỏ tới node mới vừa được chèn.

#### Ví dụ
```
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm chèn một node vào đầu danh sách
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // 1. Cấp phát bộ nhớ cho node mới
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // 2. Gán dữ liệu cho node mới
    new_node->data = new_data;

    // 3. Trỏ con trỏ 'next' của node mới tới node đầu tiên hiện tại
    new_node->next = *head_ref;

    // 4. Cập nhật con trỏ 'head' để trỏ tới node mới
    *head_ref = new_node;
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

    // Chèn các node vào đầu danh sách
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // In danh sách
    printList(head);

    return 0;
}
```
- Giải thích:
    - `insertAtBeginning`: Hàm này thực hiện chèn một `node` mới vào đầu danh sách.

    - `struct Node**head_ref`: Là tham chiếu tới con trỏ `head` của danh sách. Bằng cách truyền tham chiếu này, hàm có thể cập nhật trực tiếp con trỏ head của danh sách liên kết.
    - `new_node->next = *head_ref;`: Liên kết `node` mới với `node` đầu tiên hiện tại (nếu có) bằng cách trỏ `con trỏ next` của `node mới` tới `node mà head` hiện tại đang trỏ tới.
    - `*head_ref = new_node;`: Cập nhật `con trỏ head` để trỏ tới `node mới`, làm cho nó trở thành `node` đầu tiên trong danh sách.
    - `printList`: Hàm này duyệt qua các `node` trong danh sách và in giá trị của từng `node` ra màn hình.