#### Cấu trúc của một Node trong Linked List
Một `node` trong `Linked List` là đơn vị cơ bản để xây dựng danh sách. Nó gồm hai phần chính:

- Dữ liệu (Data): Đây là giá trị hoặc thông tin mà node lưu trữ.
- Con trỏ tới Node tiếp theo: Đây là con trỏ (hoặc tham chiếu) trỏ đến node tiếp theo trong danh sách liên kết.

#### Cấu trúc của một Node trong C
Trong ngôn ngữ C, cấu trúc của một node trong danh sách liên kết đơn có thể được định nghĩa như sau:
```
struct Node {
    int data;            // Chứa giá trị dữ liệu của node
    struct Node* next;   // Con trỏ tới node tiếp theo trong danh sách liên kết
};
```
- Giải thích:
    - `int data`: Đây là trường nơi dữ liệu hoặc giá trị được lưu trữ. Nó có thể là bất kỳ kiểu dữ liệu nào (ví dụ: int, float, char, hoặc thậm chí là một kiểu dữ liệu phức tạp hơn như struct). Trong ví dụ này, nó là một số nguyên.

    - `struct Node* next`: Đây là con trỏ trỏ tới `node` tiếp theo trong danh sách liên kết. Nó cho phép danh sách liên kết "liên kết" các node với nhau, tạo ra một chuỗi các node.

- Ví dụ
Hãy hình dung một ví dụ với một danh sách liên kết có ba node chứa các giá trị `1`, `2`, và `3`:

    - Node 1:
        - data = 1
        - next trỏ tới Node 2
    - Node 2:
        - data = 2
        - next trỏ tới Node 3
    - Node 3:
        - data = 3
        - next là NULL (vì đây là node cuối cùng)

Trong bộ nhớ, điều này có thể được hình dung như sau:
```
+---------+---------+    +---------+---------+    +---------+---------+
|   1     |  next   | -> |   2     |  next   | -> |   3     |  NULL   |
+---------+---------+    +---------+---------+    +---------+---------+
```
- Ở đây:

    - Mỗi khối đại diện cho một node.
    - Phần bên trái của mỗi khối lưu trữ dữ liệu (trường data).
    - Phần bên phải của mỗi khối lưu trữ con trỏ tới node tiếp theo (trường next).
    - Node cuối cùng trỏ tới NULL, biểu thị sự kết thúc của danh sách.