#### Nguyên tắc hoạt động của Queue
Queue hoạt động theo nguyên tắc FIFO, nghĩa là phần tử nào được đưa vào trước sẽ được lấy ra trước. Hình dung dễ hiểu nhất là khi bạn xếp hàng mua vé, người nào đến trước sẽ được phục vụ trước.
![queue](/Queue/Queue.png)

#### Các thao tác chính trong Queue
##### Enqueue (Thêm phần tử vào Queue)
Thao tác này thêm một phần tử mới vào cuối hàng đợi. Nếu Queue đã đầy (trong trường hợp sử dụng mảng với kích thước cố định), thao tác này sẽ thất bại.
##### Dequeue (Lấy phần tử ra khỏi Queue)
Thao tác này lấy phần tử ở đầu hàng đợi ra. Sau khi lấy phần tử ra, tất cả các phần tử còn lại trong hàng đợi sẽ được dịch chuyển lên một vị trí (nếu sử dụng mảng) hoặc đơn giản là thay đổi con trỏ (nếu sử dụng danh sách liên kết).
##### Peek/Front (Xem phần tử đầu của Queue)
Thao tác này chỉ xem giá trị của phần tử đầu tiên trong hàng đợi mà không lấy nó ra khỏi Queue.
##### IsEmpty (Kiểm tra Queue rỗng)
Thao tác này kiểm tra xem Queue có rỗng không, tức là không có phần tử nào trong hàng đợi.
##### IsFull (Kiểm tra Queue đầy)
Thao tác này kiểm tra xem Queue có đầy không. Nó thường chỉ áp dụng với Queue sử dụng mảng có kích thước cố định.