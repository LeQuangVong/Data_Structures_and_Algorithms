Trong cấu trúc dữ liệu Stack (ngăn xếp), top (đỉnh) là chỉ số của phần tử đang ở đỉnh của ngăn xếp. Đây là phần tử mà bạn sẽ truy xuất hoặc thay đổi khi thực hiện các thao tác như push hoặc pop.
##### Chức năng của Đỉnh Stack
- Xem Phần tử Đỉnh (Peek/Top):

    - Peek hoặc Top là thao tác để xem giá trị của phần tử nằm ở đỉnh của stack mà không loại bỏ nó. Đây là thao tác rất quan trọng để kiểm tra giá trị hiện tại ở đỉnh mà không làm thay đổi cấu trúc của stack.
- Thêm Phần tử vào Đỉnh (Push):

    - Khi bạn thêm (push) một phần tử vào stack, phần tử mới sẽ được đặt lên trên phần tử hiện tại đang ở đỉnh, và đỉnh stack sẽ được cập nhật để chỉ đến phần tử mới.
- Lấy Phần tử từ Đỉnh (Pop):

    - Khi bạn lấy (pop) một phần tử từ stack, phần tử ở đỉnh sẽ được loại bỏ và đỉnh stack sẽ được cập nhật để chỉ đến phần tử mới ở trên.
- Khi một stack (ngăn xếp) trống, chỉ số của đỉnh stack (top) thường được đặt bằng -1. Đây là một cách phổ biến để chỉ ra rằng stack hiện tại không chứa bất kỳ phần tử nào.