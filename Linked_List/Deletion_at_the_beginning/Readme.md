Để xóa một node ở đầu của một Linked List trong C, bạn cần thực hiện các bước sau:

- Kiểm tra danh sách: Đảm bảo rằng danh sách không rỗng.
- Cập nhật con trỏ head: Trỏ head tới node tiếp theo sau node đầu tiên.
- Giải phóng bộ nhớ của node đầu tiên: Giải phóng bộ nhớ mà node đầu tiên chiếm dụng.
#### Ví dụ
Xóa một node ở đầu của Linked List:
```
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm xóa node ở đầu danh sách
void deleteAtBeginning(struct Node** head_ref) {
    // 1. Kiểm tra nếu danh sách rỗng
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    // 2. Lưu trữ node hiện tại sẽ bị xóa
    struct Node* temp = *head_ref;

    // 3. Cập nhật con trỏ head để trỏ tới node tiếp theo
    *head_ref = (*head_ref)->next;

    // 4. Giải phóng bộ nhớ của node đầu tiên
    free(temp);
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
    // Khởi tạo Linked List với 3 node
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // In danh sách trước khi xóa
    printf("Before deletion:\n");
    printList(head);

    // Xóa node đầu tiên
    deleteAtBeginning(&head);

    // In danh sách sau khi xóa
    printf("After deletion:\n");
    printList(head);

    return 0;
}
```
- Giải thích:
    - `deleteAtBeginning`: Hàm này thực hiện việc `xóa node đầu tiên` của danh sách.
    - `Kiểm tra danh sách rỗng`: Nếu danh sách trống (head là NULL), không có node nào để xóa.
    - `Lưu trữ node đầu tiên`: Con trỏ tạm thời temp lưu trữ địa chỉ của node đầu tiên để giải phóng sau này.
    - `Cập nhật con trỏ head`: `Con trỏ head` được cập nhật để `trỏ` tới `node thứ hai`, `node này` sẽ trở thành `node đầu tiên mới`.
    - `Giải phóng bộ nhớ`: Giải phóng bộ nhớ của `node cũ` bằng cách sử dụng `hàm free()`.
    - `printList`: Hàm này duyệt qua `các node` trong danh sách và in giá trị của từng `node` ra màn hình.