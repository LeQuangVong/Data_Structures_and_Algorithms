#### Chèn Phần tử vào Mảng
Chương trình này thực hiện các bước sau:

- Nhận đầu vào từ người dùng cho mảng ban đầu.
- Nhận vị trí và giá trị của phần tử mới cần chèn.
- Di chuyển các phần tử để tạo khoảng trống.
- Chèn phần tử mới vào vị trí được chỉ định.
- In mảng sau khi chèn.
```
#include <stdio.h>

int main() {
    int n, pos, value;

    // Nhập số lượng phần tử của mảng
    printf("Nhập số lượng phần tử trong mảng: ");
    scanf("%d", &n);

    // Khai báo mảng có kích thước lớn hơn một đơn vị để có thể chèn thêm phần tử
    int arr[n + 1];

    // Nhập các phần tử của mảng
    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < n; i++) {
        printf("Phần tử [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Nhập vị trí và giá trị của phần tử mới cần chèn
    printf("Nhập vị trí để chèn (0 đến %d): ", n);
    scanf("%d", &pos);
    
    // Kiểm tra xem vị trí có hợp lệ không
    if (pos < 0 || pos > n) {
        printf("Vị trí không hợp lệ!\n");
        return 1;
    }

    printf("Nhập giá trị cần chèn: ");
    scanf("%d", &value);

    // Di chuyển các phần tử để tạo khoảng trống
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Chèn phần tử mới vào vị trí được chỉ định
    arr[pos] = value;
    n++; // Tăng kích thước logic của mảng sau khi chèn

    // In mảng sau khi chèn
    printf("Mảng sau khi chèn là: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```
##### Giải thích Mã lệnh:
- Nhập Mảng Ban Đầu:

    - Chương trình yêu cầu người dùng nhập số lượng phần tử và sau đó nhập từng phần tử vào mảng.
- Nhập Vị trí và Giá trị Cần Chèn:

    - Người dùng nhập vị trí mà họ muốn chèn phần tử mới và giá trị của phần tử đó.
- Kiểm tra Vị trí Hợp lệ:

    - Chương trình kiểm tra xem vị trí chèn có hợp lệ không (phải nằm trong khoảng từ `0` đến `n`).
- Di chuyển Các Phần tử:

    - Để tạo khoảng trống cho phần tử mới, các phần tử từ vị trí chèn trở về sau đều được di chuyển một vị trí sang phải.
- Chèn Phần tử Mới:

    - Phần tử mới được chèn vào vị trí xác định.
- In Mảng Sau Khi Chèn:

    - Cuối cùng, chương trình in mảng đã được cập nhật với phần tử mới.
##### Độ Phức Tạp Thời Gian:
- Chèn một phần tử vào giữa mảng: Độ phức tạp thời gian là `O(n)` vì trong trường hợp xấu nhất, bạn cần phải di chuyển tất cả các phần tử (khi chèn vào đầu mảng).
- Truy cập và cập nhật phần tử: Độ phức tạp thời gian là `O(1)` cho mỗi thao tác.