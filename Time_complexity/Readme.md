Để tìm độ phức tạp thời gian của một thuật toán, cần phân tích cách thời gian thực thi của thuật toán tăng lên khi kích thước đầu vào tăng. 
#### Xác định các thao tác cơ bản
Thao tác cơ bản là những thao tác tốn thời gian không đổi, thường được biểu diễn là ```O(1)```.
- Ví dụ như các phép toán số học, phép gán, so sánh, và truy cập phần tử của mảng theo chỉ số.

Mục tiêu của bạn là xác định thao tác cơ bản quan trọng nhất trong thuật toán, tức là thao tác được thực hiện nhiều nhất khi kích thước đầu vào tăng.
#### Xác định kích thước đầu vào (n)
Kích thước đầu vào `n` thường là kích thước của cấu trúc dữ liệu hoặc số phần tử cần xử lý.
- Ví dụ, trong thuật toán sắp xếp,`n` là số lượng phần tử trong mảng.
#### Phân tích các vòng lặp
- Vòng lặp For: Nếu một vòng lặp chạy từ 1 đến `n`, độ phức tạp thời gian thường là `O(n)`. 
Các vòng lặp lồng nhau sẽ nhân các độ phức tạp thời gian với nhau. 
    - Ví dụ, một vòng lặp lồng nhau mà cả hai vòng đều chạy từ 1 đến n sẽ có độ phức tạp là $O(n^2)$.

- Vòng lặp While: Độ phức tạp thời gian phụ thuộc vào điều kiện và cách nó liên quan đến `n`. Nếu điều kiện `giảm tỷ lệ` với `n`, độ phức tạp có thể là `O(n)`.

#### Phân tích các lời gọi đệ quy
Khi xử lý đệ quy, bạn có thể sử dụng phương trình truy hồi để biểu diễn độ phức tạp thời gian. Ví dụ, độ phức tạp thời gian của một thuật toán đệ quy chia vấn đề thành hai phần bằng nhau (như Merge Sort) thường được phân tích bằng Định lý Master.
#### Bỏ qua các hằng số và các số hạng bậc thấp hơn
Độ phức tạp thời gian tập trung vào tốc độ tăng trưởng khi `n` trở nên lớn. Điều này có nghĩa là các hằng số và các số hạng không chiếm ưu thế sẽ bị bỏ qua. 
Ví dụ, 
O(3n+10) sẽ đơn giản hóa thành O(n), và $O(n^2 +n)$ sẽ đơn giản hóa thành $O(n^2)$.
#### Xác định trường hợp xấu nhất
Độ phức tạp thời gian thường được đánh giá trong trường hợp xấu nhất, đảm bảo thuật toán hoạt động trong giới hạn nhất định bất kể đầu vào là gì. Bạn cần phân tích trường hợp xấu nhất bằng cách xem xét đầu vào nào khiến thuật toán tốn thời gian nhiều nhất.
#### Kết hợp các kết quả
Nếu thuật toán của bạn có các phần khác nhau (ví dụ: một vòng lặp sau đó là một vòng lặp khác), bạn cần kết hợp các độ phức tạp. Nếu các phần độc lập, bạn cộng các độ phức tạp với nhau, nhưng nhớ rằng bậc cao nhất sẽ chiếm ưu thế.
#### Các độ phức tạp thời gian phổ biến
- O(1): Thời gian hằng số.
- O(logn): Thời gian logarithmic, phổ biến trong các thuật toán chia nhỏ kích thước vấn đề (ví dụ: tìm kiếm nhị phân).
- O(n): Thời gian tuyến tính, thời gian tăng tỷ lệ thuận với kích thước đầu vào.
- O(nlogn): Thời gian linearithmic, phổ biến trong các thuật toán sắp xếp hiệu quả như Merge Sort.
- $O(n^2)$: Thời gian bậc hai, thường thấy trong các thuật toán có vòng lặp lồng nhau.
- $O(2^n)$: Thời gian bậc mũ, phổ biến trong các thuật toán xem xét tất cả các tập con (ví dụ: một số thuật toán đệ quy).
#### Example
```
void exampleFunction(int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            count++;
        }
    }
}
```
Giải pháp từng bước:
- Xác định kích thước đầu vào
Kích thước đầu vào `n` được đưa vào trực tiếp trong hàm dưới dạng tham số.
- Phân tích các vòng lặp
Đoạn mã có hai vòng lặp lồng nhau.

    - Vòng lặp bên ngoài: Vòng lặp bên ngoài chạy từ `i=0` đến `i<n`. Do đó, nó chạy `n` lần.

    - Vòng lặp bên trong: Vòng lặp bên trong chạy từ `j=i` đến `j<n`. Số lần vòng lặp này chạy phụ thuộc vào giá trị hiện tại của `i`. Khi `i=0`, vòng lặp bên trong chạy `n` lần; khi `i=1`, nó chạy `n−1` lần, và cứ thế.

- Tính tổng số thao tác
    - Tổng số lần vòng lặp bên trong thực thi có thể được biểu diễn như sau:
    Tổng số đếm $= n+(n−1)+(n−2)+…+1$
    - Đây là một chuỗi số học, và tổng của nó có thể được tính bằng công thức:
    $S = \frac{n(n+1)}{2}$
    - Vì vậy, tổng số thao tác là:
    $S = \frac{n^2 + n}{2}$ 
- Xác định Độ Phức tạp Thời gian
Khi đánh giá độ phức tạp thời gian, chúng ta tập trung vào số hạng tăng nhanh nhất khi `n` tăng lên.
Trong trường hợp này, số hạng $\frac{n(n+1)}{2}$ được đơn giản hóa thành $O(n^2)$.
    - Lý do là: $n^2$ chiếm ưu thế so với `n` khi `n` trở nên lớn.
    - Các hằng số và các số hạng bậc thấp hơn đều bị bỏ qua trong ký hiệu Big-O.
- Kết luận
Độ phức tạp thời gian của hàm `exampleFunction` là $O(n^2)$.
- Giải thích
Điều này có nghĩa là nếu kích thước đầu vào tăng gấp đôi, thời gian thực hiện của thuật toán sẽ tăng lên khoảng bốn lần.