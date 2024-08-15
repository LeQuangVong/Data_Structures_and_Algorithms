#### Stack là gì?
Stack (ngăn xếp) là một cấu trúc dữ liệu dạng danh sách tuyến tính hoạt động theo nguyên tắc LIFO (Last In, First Out), nghĩa là phần tử được thêm vào cuối cùng sẽ là phần tử được lấy ra đầu tiên. Stack có thể được tưởng tượng như một chồng đĩa, chỉ có thể thêm (push) hoặc lấy ra (pop) một đĩa từ đỉnh chồng.

#### Các thao tác cơ bản trên Stack
- `Push (Thêm phần tử)`: Thêm một phần tử vào đỉnh của Stack.
- `Pop (Lấy phần tử)`: Lấy và loại bỏ phần tử ở đỉnh của Stack.
- `Peek/Top (Xem phần tử đỉnh)`: Xem phần tử nằm ở đỉnh của Stack mà không lấy nó ra.
- `IsEmpty (Kiểm tra rỗng)`: Kiểm tra xem Stack có rỗng hay không.
- `IsFull (Kiểm tra đầy)`: Kiểm tra xem Stack có đầy hay không (nếu Stack có giới hạn kích thước).
#### Cách Stack Hoạt động
Giả sử có một stack trống. Các thao tác sau đây sẽ diễn ra:
- Push: Giả sử bạn đẩy các phần tử 1, 2, 3 vào stack theo thứ tự đó. Stack sẽ trông như thế này:
```
3  <- Đỉnh (Top)
2
1
```
- Pop: Khi bạn thực hiện thao tác pop, phần tử 3 sẽ được lấy ra khỏi stack:
```
2  <- Đỉnh (Top)
1
```
- Push: Nếu bạn thêm phần tử 4, stack sẽ trông như sau:
```
4  <- Đỉnh (Top)
2
1
```
- Peek: Thao tác này sẽ trả về giá trị 4, nhưng stack không thay đổi.

#### Ứng dụng của Stack
- Duyệt ngược: Stack được sử dụng để đảo ngược thứ tự của các phần tử.
- Quản lý biểu thức toán học: Stack thường được sử dụng trong quá trình phân tích và đánh giá biểu thức (ví dụ: chuyển từ biểu thức trung tố sang hậu tố).
- Quay lui (Backtracking): Các thuật toán như quay lui (backtracking) dùng stack để theo dõi các bước đi trước đó.
- Hệ thống gọi hàm: Stack được sử dụng để lưu trữ trạng thái của các hàm gọi trong quá trình thực thi chương trình.