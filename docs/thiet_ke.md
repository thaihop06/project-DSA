# Thiết kế Bloom Filter

## Cấu trúc dữ liệu
- Bit-array kích thước m
- k hàm băm

## Nguyên lý
- Thêm ID: bật k bit tương ứng
- Kiểm tra ID: nếu tất cả bit = 1 → có thể tồn tại

## Độ phức tạp
- Add: O(k)
- Check: O(k)
