# Bộ lọc trùng lặp ID gói tin (Bloom Filter giả lập) 

## Mục tiêu 
Mô phỏng Bloom filter để phát hiện ID đã xuất hiện, phân tích tỉ lệ false positive.

## Dữ liệu vào / Dữ liệu ra
Danh sách ID (số nguyên hoặc chuỗi).
Tham số: kích thước bit-array m, số hàm băm k.
Chương trình chạy menu console, hiển thị kết quả truy vấn/thống kê.
Xuất ít nhất 1 file báo cáo kết quả (CSV) để giảng viên kiểm tra. 

## Yêu cầu chức năng bắt buộc
Bit-array cho Bloom Filter, thay đổi m,k 
Hệ thống hàm băm và ánh xạ ID. 
Hash table lưu dữ liệu thật để đối chiếu. 

## Yêu cầu cấu trúc dữ liệu và thuật toán
Bắt buộc: mảng bit.
Bắt buộc: hash functions; thêm 1 hash table đơn giản làm 'ground truth' để đo false positive.
Thuật toán: thao tác bit, thống kê. 

## Phân công 3 người 
Người 1: Thiết kế cấu trúc project, viết menu nhập/xuất dữ liệu và tổng hợp báo cáo kết quả. 
Người 2: Cài đặt Bloom Filter và hash table theo yêu cầu, kiểm tra chức năng cơ bản. 
Người 3: Thiết kế bộ test, đo false positive, phân tích thuật toán và hướng dẫn chạy chương trình. 

## Bộ test tối thiểu
Tập 1000 ID, kiểm tra false positive khi m nhỏ và khi m lớn.
Kiểm tra ID chắc chắn đã thêm => phải trả 'có'.
