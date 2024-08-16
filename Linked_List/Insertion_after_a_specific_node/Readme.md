Để chèn một `node mới` vào sau một `node cụ thể` trong một `Linked List`, bạn cần thực hiện các bước sau:

- Tìm `node cụ thể`: Xác định `vị trí` của `node` mà muốn `chèn` `node mới` vào `sau nó`.
- Tạo một `node mới`: Cấp phát bộ nhớ cho `node mới` và `gán dữ liệu cho nó`.
- `Liên kết node mới`: Cập nhật `con trỏ next` của `node mới` để trỏ đến `node` mà `node cụ thể` đang trỏ đến, và sau đó cập nhật `con trỏ next` của `node cụ thể` để trỏ đến `node mới`.
#### Ví dụ
Chèn một `node mới` sau một `node cụ thể` trong Linked List:
```
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm chèn một node mới sau một node cụ thể
void insertAfter(struct Node* prev_node, int new_data) {
    // 1. Kiểm tra nếu node trước đó là NULL
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    // 2. Cấp phát bộ nhớ cho node mới
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // 3. Gán dữ liệu cho node mới
    new_node->data = new_data;

    // 4. Liên kết node mới với node sau node trước đó
    new_node->next = prev_node->next;

    // 5. Liên kết node trước đó với node mới
    prev_node->next = new_node;
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

    // Chèn một node mới sau node thứ hai
    insertAfter(second, 4);

    // In danh sách
    printList(head);

    return 0;
}
```
- Giải thích:
    - `insertAfter`: Hàm này thực hiện chèn một `node mới` sau một `node cụ thể (prev_node)`.
    - `Kiểm tra prev_node`: Nếu `prev_node` là `NULL`, nghĩa là `node trước đó` không tồn tại, và bạn không thể chèn sau node này.
    - `Cấp phát bộ nhớ cho node mới`: Một `node mới` được tạo ra và gán giá trị cho `trường data`.
    - Liên kết `node mới` với `node tiếp theo` của `prev_node`: `Con trỏ next` của `node mới` sẽ `trỏ` đến `node` mà `prev_node` đang trỏ tới.
    - Liên kết `prev_node` với `node mới`: `Con trỏ next` của `prev_node` được cập nhật để trỏ tới `node mới`.
    - `printList`: Hàm này duyệt qua các `node` trong danh sách và in giá trị của từng `node` ra màn hình.