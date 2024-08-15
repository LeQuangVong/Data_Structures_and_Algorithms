Last In First Out (LIFO) là nguyên tắc hoạt động chính của cấu trúc dữ liệu Stack (ngăn xếp). Nguyên tắc này có nghĩa là phần tử được thêm vào cuối cùng sẽ là phần tử được lấy ra đầu tiên. Để giúp bạn hiểu rõ hơn về LIFO và cách nó hoạt động trong stack, hãy xem xét các khái niệm và ví dụ dưới đây.

#### Nguyên Tắc LIFO
- Last In (Cuối cùng vào): Phần tử được thêm vào stack gần đây nhất sẽ nằm ở đỉnh của stack.
- First Out (Đầu tiên ra): Phần tử được lấy ra đầu tiên là phần tử nằm ở đỉnh của stack, nghĩa là phần tử được thêm vào gần nhất.
#### Cấu Trúc Stack và Nguyên Tắc LIFO
- Hình Dạng Của Stack:
```
Top
 |
 v
[5]  <- Đỉnh (phần tử được thêm gần đây nhất)
[4]
[3]
[2]
[1]  <- Cơ sở (phần tử được thêm đầu tiên)
```
- Phần tử 5 được thêm vào cuối cùng và sẽ được lấy ra đầu tiên.
- Phần tử 1 được thêm đầu tiên và sẽ là phần tử cuối cùng được lấy ra khi các phần tử khác đã được loại bỏ.
#### Thao Tác Cơ Bản Trong Stack
- Push (Thêm phần tử): Thao tác thêm một phần tử vào đỉnh của stack. Phần tử mới sẽ trở thành đỉnh mới của stack.

Ví dụ: Nếu bạn push các số 1, 2, 3 vào stack theo thứ tự đó, stack sẽ trông như sau:
```
3  <- Đỉnh
2
1
```
- Pop (Lấy phần tử): Thao tác lấy phần tử từ đỉnh của stack. Phần tử này sẽ được loại bỏ khỏi stack và phần tử tiếp theo sẽ trở thành đỉnh mới.

Ví dụ: Nếu bạn pop một phần tử, phần tử 3 sẽ được lấy ra và stack sẽ trông như sau:
```
2  <- Đỉnh
1
```
- Peek/Top (Xem phần tử đỉnh): Thao tác xem giá trị của phần tử ở đỉnh stack mà không loại bỏ nó.

Ví dụ: Peek sẽ trả về giá trị 2 mà không thay đổi stack.
