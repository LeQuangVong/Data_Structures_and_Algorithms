#### Stack Overflow
Stack overflow xảy ra khi bạn cố gắng thêm (push) một phần tử vào stack khi stack đã đầy. Điều này xảy ra vì không còn không gian trống trong stack để chứa phần tử mới. Stack overflow có thể dẫn đến sự cố chương trình hoặc lỗi hệ thống nếu không được xử lý đúng cách.

##### Nguyên nhân:
- Kích thước giới hạn của stack: Trong các ứng dụng thực tế, stack thường có kích thước cố định. Khi kích thước này đạt đến giới hạn tối đa, không thể thêm phần tử mới.

- Lỗi lập trình: Trong một số trường hợp, lỗi lập trình có thể dẫn đến việc thêm quá nhiều phần tử vào stack.

##### Xử lý Stack Overflow:
- Kiểm tra đầy: Trước khi thực hiện thao tác push, bạn nên kiểm tra xem stack có đầy không bằng cách sử dụng hàm kiểm tra như isFull().

- Tăng kích thước stack: Trong các hệ thống động, bạn có thể thay đổi kích thước của stack nếu cần thiết, nhưng điều này phụ thuộc vào việc cấu trúc dữ liệu có cho phép điều chỉnh kích thước hay không.

Ví dụ:
```
void push(int value) {
    if (isFull()) {
        printf("Stack đầy. Không thể thêm phần tử %d\n", value);
    } else {
        stack[++top] = value;
        printf("Đã thêm phần tử %d vào stack\n", value);
    }
}
```
#### Stack Underflow
Stack underflow xảy ra khi bạn cố gắng lấy (pop) một phần tử từ stack khi stack rỗng. Điều này xảy ra vì không có phần tử nào trong stack để lấy ra. Stack underflow có thể dẫn đến lỗi hoặc hành vi không mong muốn trong chương trình nếu không được xử lý đúng cách.

##### Nguyên nhân:
- Lỗi lập trình: Việc cố gắng thực hiện thao tác pop trên một stack rỗng thường là dấu hiệu của lỗi lập trình, chẳng hạn như không kiểm tra trạng thái của stack trước khi lấy phần tử.

- Quản lý sai trạng thái: Nếu stack không được quản lý đúng cách (ví dụ, không giảm kích thước sau khi pop), bạn có thể gặp tình trạng stack underflow.

- Xử lý Stack Underflow:
Kiểm tra rỗng: Trước khi thực hiện thao tác pop, bạn nên kiểm tra xem stack có rỗng không bằng cách sử dụng hàm kiểm tra như isEmpty().
Ví dụ:
```
int pop() {
    if (isEmpty()) {
        printf("Stack rỗng. Không thể thực hiện pop\n");
        return -1;  // Trả về giá trị lỗi
    } else {
        return stack[top--];
    }
}
```
