  Báo cáo về dự án cuối kì

1) Cách lấy code và chạy chương trình	
-Nhấn vào code trên github tải file zip về và giải nén
-Mở terminal , vào thư mục đã giải nén 
-Ghi lệnh “mingw32-make” rồi nhấn Enter
-Tiếp theo ghi lệnh “./main” để mở file exe

2 Mô tả chung về trò chơi
Mô tả : 
-Trò chơi con chim vượt chướng ngại vật là ống nước thao tác bằng chuột hoặc bàn phím 
Ý tưởng :
- Xác định các đối tượng của trò chơi : Vật (con chim ) , chướng ngại vật (ống nước) , nền trò chơi ( gồm có hiệu ứng và ảnh nền ) , Đối tượng liên quan các đối tượng khác (Đối tượng này có thể có nhiệm vụ gắn các đối tượng khác với nhau )
-Tưởng tương các bước mà game sẽ làm khi game hoàn thành để xác định nhiệm vụ cũng như thứ tự các bước 
- Khởi tạo đối tượng và nhiệm vụ đối tượng
- Xác định mối liên hệ giữa các đối tượng để tạo đối tượng chung (Có thể có nhiều đối tượng chung )
- Đối tượng chung cần liên kết các đối tượng để hoạt động hiệu quả
- Tìm cách xây dựng các đối tượng và chức năng logic , dễ hiểu 


3 Các chức năng đã cài đặt
- Hiển thị đối tượng lên màn hình
- Cho các đối tượng hoạt động theo điều khiển bằng bàn phím hoặc chuột
- Tính điểm và hiển thị
- Thêm hiệu ứng và âm nhạc
- Chơi nhiều lần
- Link video minh họa https://www.youtube.com/watch?v=ExJzxmRnaSo
4 Các kĩ thuật lập trình đã sử dụng
Lớp dữ liệu class : Dùng để khởi tạo các đối tượng
Các hàm của thư viện SDL : Dùng để hiển thị hình ảnh và âm thanh game lên màn hình hay xử lí bàn phím
VD:
SDL_PollEvent : Xử lí bàn phím
SDL_Texture : hiển thị hình ảnh
SDL_Init : khởi tạo các đối tựng trong SDL
Vector : Xử lí 1 tập hợp của đối tượng 
Vòng lặp : Có vai trò quan trong trong game , giúp cho game hoạt động
5 Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình
Kết luận :
- Khi lập trình cần xác định đối tượng hay mục tiêu mình sẽ tạo ra 
- Chia nhỏ đối tượng thành các đối tượng nhỏ 
- Khởi tạo ra các đối tượng ấy và xác định chức năng của đối tượng để viết chức năng cho nó
- Xác định điểm chung của các đối tượng để có thể tạo 1 lớp cơ sở chung
Hướng phát triển :
+ Có thể tăng tốc độ của chim ( tăng tốc độ nền và ống nước)
+ Tạo thêm nhiều level chơi với các địa hình khác nhau
+ Có thể tạo ra cuộc thi có nhiều người chơi chơi với nhau
+ Có thể tạo ra 1 game khác thay ống nước bằng tia sét lá bằng thiên thạch con chim bằng tàu vũ trụ …
Tâm đắc :
	Bản thân rút ra được nhiều kết luận và kinh nghiệm của bản thân sau quá trình làm dự án :

Hiểu thêm cách xác định mục tiêu đối tượng , chia nhỏ mục tiêu đối tượng ấy .
Thêm kinh nghiệm liên kết các mục tieu đối tượng ấy để hoàn thành mục tiêu đối tượng cần tạo ra
Được thực hành để hoàn thiện code , tối ưu hóa code như bằng là modun hóa code









