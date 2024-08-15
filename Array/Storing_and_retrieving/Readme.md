#### Lưu trữ, Truy xuất và Cập nhật Phần tử trong Mảng
Chương trình này sẽ thực hiện các thao tác sau:
- Nhận mảng đầu vào từ người dùng.
- In các phần tử của mảng.
- Tìm kiếm một giá trị trong mảng và cập nhật giá trị đó nếu tìm thấy.
- In mảng sau khi cập nhật.
```
#include <stdio.h>

int main() {
    int n;

    // Nhập số lượng phần tử của mảng
    printf("Nhập số lượng phần tử trong mảng: ");
    scanf("%d", &n);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhập các phần tử của mảng: \n");
    for (int i = 0; i < n; i++) {
        printf("Phần tử [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // In các phần tử của mảng
    printf("Các phần tử trong mảng là: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Tìm kiếm một phần tử trong mảng và cập nhật giá trị
    int x, newValue;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Nhập giá trị mới: ");
            scanf("%d", &newValue);
            arr[i] = newValue;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Cập nhật thành công.\n");
    } else {
        printf("Không tìm thấy giá trị trong mảng.\n");
    }

    // In mảng sau khi cập nhật
    printf("Mảng sau khi cập nhật là: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```
##### Giải thích Mã lệnh:
- Khai báo và Khởi tạo Mảng:

    - `int arr[n];`: tạo một mảng có kích thước `n` dựa trên số lượng phần tử mà người dùng nhập vào.
- Nhập Dữ liệu vào Mảng:

    - Vòng lặp `for` để nhập từng phần tử từ người dùng và lưu trữ chúng vào mảng.
- In các Phần tử của Mảng:

    - Sử dụng một vòng lặp `for` khác để in tất cả các phần tử của mảng.
- Tìm kiếm và Cập nhật Phần tử:

    - Chương trình yêu cầu người dùng nhập một giá trị để tìm trong mảng. Nếu tìm thấy, nó sẽ yêu cầu nhập giá trị mới và cập nhật phần tử đó.
    - Sử dụng biến `found` để kiểm tra xem giá trị có được tìm thấy hay không.
- In Mảng Sau khi Cập nhật:

    - Sau khi cập nhật, chương trình in lại mảng để hiển thị kết quả.
##### Độ Phức Tạp Thời Gian:
- Lưu trữ và Truy xuất: Độ phức tạp thời gian cho cả hai thao tác này là `O(1)`.
- Tìm kiếm: Độ phức tạp thời gian của thao tác tìm kiếm là `O(n)`, vì trong trường hợp xấu nhất, bạn có thể phải duyệt qua tất cả các phần tử của mảng.
- Cập nhật: Việc cập nhật giá trị của phần tử sau khi tìm thấy có độ phức tạp thời gian là `O(1)`.