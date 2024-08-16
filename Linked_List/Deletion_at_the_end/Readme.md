Để xóa một node ở cuối của một Linked List trong C, cần thực hiện các bước sau:

- Kiểm tra danh sách: Đảm bảo rằng danh sách không rỗng và có ít nhất một node.
- Duyệt đến node kế cuối: Sử dụng một con trỏ tạm thời để duyệt qua danh sách đến node thứ hai từ cuối (node kế cuối).
- Cập nhật con trỏ next của node kế cuối: Trỏ con trỏ next của node này tới NULL.
- Giải phóng bộ nhớ của node cuối cùng: Giải phóng bộ nhớ mà node cuối cùng chiếm dụng.
#### Ví dụ
Xóa một node ở cuối của Linked List:
```
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm xóa node ở cuối danh sách
void deleteAtEnd(struct Node** head_ref) {
    // 1. Kiểm tra nếu danh sách rỗng
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    // 2. Kiểm tra nếu chỉ có một node
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    // 3. Duyệt tới node kế cuối
    struct Node* temp = *head_ref;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // 4. Giải phóng bộ nhớ của node cuối cùng
    free(temp->next);

    // 5. Cập nhật con trỏ next của node kế cuối thành NULL
    temp->next = NULL;
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

    // Xóa node cuối cùng
    deleteAtEnd(&head);

    // In danh sách sau khi xóa
    printf("After deletion:\n");
    printList(head);

    return 0;
}
```
- Giải thích:
    - `deleteAtEnd`: Hàm này thực hiện việc xóa node cuối cùng của danh sách.
    - `Kiểm tra danh sách rỗng`: Nếu danh sách trống (head là NULL), không có node nào để xóa.
    - `Kiểm tra nếu danh sách chỉ có một node`: Nếu chỉ có một node, node đó sẽ bị xóa, và head được cập nhật thành NULL.
    - `Duyệt đến node kế cuối`: Con trỏ temp duyệt qua danh sách cho đến khi gặp node kế cuối (node mà next->next là NULL).
    - `Giải phóng node cuối cùng`: Node cuối cùng được giải phóng bằng cách sử dụng hàm free().
    - `Cập nhật con trỏ next của node kế cuối`: Con trỏ next của node kế cuối được cập nhật để trỏ đến NULL, đánh dấu nó là node cuối cùng mới.
    - `printList`: Hàm này duyệt qua các node trong danh sách và in giá trị của từng node ra màn hình.