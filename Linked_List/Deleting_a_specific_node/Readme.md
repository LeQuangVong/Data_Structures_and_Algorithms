Để xóa một node cụ thể trong một Linked List ở C, bạn cần xác định vị trí của node đó, sau đó cập nhật con trỏ next của node trước đó để bỏ qua node cần xóa, và cuối cùng là giải phóng bộ nhớ của node bị xóa.

#### Các bước thực hiện:
- Kiểm tra danh sách: Đảm bảo rằng danh sách không rỗng.
- Tìm node trước node cần xóa: Duyệt qua danh sách để tìm node ngay trước node cần xóa.
- Cập nhật con trỏ next của node trước đó: Trỏ con trỏ next của node trước đó tới node sau node cần xóa.
- Giải phóng bộ nhớ của node cần xóa: Giải phóng bộ nhớ mà node cần xóa chiếm dụng.
#### Ví dụ
Xóa một node cụ thể trong Linked List:
```
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm xóa node cụ thể trong danh sách
void deleteNode(struct Node** head_ref, int key) {
    // 1. Khởi tạo con trỏ tạm để duyệt danh sách
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // 2. Kiểm tra nếu node đầu tiên chính là node cần xóa
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Cập nhật head
        free(temp); // Giải phóng bộ nhớ của node đầu tiên
        return;
    }

    // 3. Tìm node chứa key cần xóa, và giữ lại node trước đó
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 4. Nếu không tìm thấy node chứa key, thoát khỏi hàm
    if (temp == NULL) return;

    // 5. Liên kết node trước đó với node tiếp theo, bỏ qua node cần xóa
    prev->next = temp->next;

    // 6. Giải phóng bộ nhớ của node cần xóa
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
    // Khởi tạo Linked List với 4 node
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    // In danh sách trước khi xóa
    printf("Before deletion:\n");
    printList(head);

    // Xóa node chứa giá trị 3
    deleteNode(&head, 3);

    // In danh sách sau khi xóa
    printf("After deletion:\n");
    printList(head);

    return 0;
}
```
- Giải thích:
    - `deleteNode`: Hàm này thực hiện việc xóa một `node cụ thể` có giá trị key.
    - `Kiểm tra nếu node đầu tiên chứa giá trị cần xóa`: Nếu `node đầu tiên` chứa giá trị cần xóa (key), cập nhật `con trỏ head` để `trỏ` tới `node tiếp theo` và giải phóng bộ nhớ của `node đầu tiên`.
    - `Duyệt tìm node cần xóa`: Nếu `node đầu tiên` không chứa giá trị key, duyệt qua danh sách để tìm `node` chứa giá trị cần xóa, đồng thời giữ lại `node trước đó`.
    - `Cập nhật con trỏ next của node trước đó`: Nếu tìm thấy `node chứa giá trị key`, `con trỏ next` của `node trước đó (prev)` sẽ trỏ tới `node tiếp theo` sau `node cần xóa`.
    - `Giải phóng bộ nhớ`: Giải phóng bộ nhớ của `node chứa giá trị key` bằng cách sử dụng `hàm free()`.
    - `printList`: Hàm này duyệt qua các `node` trong danh sách và in giá trị của từng `node` ra màn hình.