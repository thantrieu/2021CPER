#include <stdio.h>
#include <string.h>
#include "staff.h"
#include "timesheet.h"
#include "work.h"

/*
* @author Branium Academy
*/

int main()
{
	TimeSheet sheets[200];
	Work works[100];
	Staff staffs[200];
	size_t numOfTimeSheet = 0;
	size_t numOfStaff = 0;
	size_t numOfWork = 0;
	// đọc file khi chương trình khởi động
	readFileStaff(staffs, &numOfStaff);
	readFileWork(works, &numOfWork);
	readFileTimeSheet(sheets, &numOfTimeSheet);

	int choice;
	do {
		puts("================= QUAN LY BANG CHAM CONG =================");
		puts("01. Them moi nhan vien vao danh sach");
		puts("02. Hien thi danh sach nhan vien");
		puts("03. Them moi cong viec vao danh sach");
		puts("04. Hien thi danh sach cong viec");
		puts("05. Tao bang cham cong cho tung nhan vien");
		puts("06. Tinh so gio lam viec thuc te cho NV trong BCC");
		puts("07. Hien thi thong tin bang cham cong");
		puts("08. Xoa 1 ban ghi trong bang cham cong theo ma BCC");
		puts("09. Tinh thu nhap cho tung NV trong BCC");
		puts("10. Sap xep danh sach BCC theo luong giam dan");
		puts("11. Cap nhat thoi gian checkin/out trong BCC theo ma BCC");
		puts("12. Ghi danh sach tai khoan vao file");
		puts("0. Thoat chuong trinh");
		printf("Xin moi chon: ");
		scanf("%d", &choice);
		printf("================= Chuc nang so %d ================\n", choice);

		switch (choice)
		{
		case 0:
			system("cls");
			puts("\n");
			puts("\t\t\t========================================");
			puts("\t\t\t===> CAM ON BAN DA SU DUNG DICH VU! <===");
			puts("\t\t\t========================================");
			break;
		case 1:
		{	// thêm nhân viên mới
			system("cls");
			char id[20];
			printf("%s", "Nhap ma NV: ");
			scanf("%*c%19[^\n]", id);
			// kiểm tra xem sv có mã id này đã tồn tại chưa
			int index = findStaffById(staffs, numOfStaff, id);
			if (index != -1) {
				puts("--> Nv nay da ton tai. Hay nhap ma khac! <--");
			}
			else {
				strcpy(staffs[numOfStaff].id, id);
				// nhập các thông tin còn lại của nhân viên
				createStaffInfo(&staffs[numOfStaff]);
				numOfStaff++;
			}
			break;
		}
		case 2:
		{	// hiển thị danh sách nhân viên
			system("cls"); // xóa màn hình
			if (numOfStaff > 0) {
				showStaffsInfo(staffs, numOfStaff);
			}
			else {
				puts("--> Danh sach rong! <--");
			}
			break;
		}
		case 3:
		{
			// nhập thêm công việc mới
			int id;
			printf("%s", "Nhap ma cong viec: ");
			scanf("%d", &id);
			// kiểm tra xem công việc có id này đã tồn tại chưa
			int index = findWorkById(works, numOfWork, id);
			if (index != -1) {
				puts("--> Mon hoc nay da ton tai. Hay nhap ma khac! <--");
			}
			else {
				works[numOfWork].id = id;
				// nhập các thông tin còn lại của công việc
				createWorkInfo(&works[numOfWork]);
				numOfWork++;
			}
			break;
		}
		case 4:
		{	// hiển thị danh sách công việc
			system("cls");
			if (numOfWork > 0) {
				showWorksInfo(works, numOfWork);
			}
			else {
				puts("--> Danh sach rong! <--");
			}
			break;
		}
		case 5:
		{
			system("cls");
			int id;
			printf("%s", "Nhap ma bang cham cong: ");
			scanf("%d", &id);
			int index = findTimeSheetById(sheets, numOfTimeSheet, id);
			if (index != -1) {
				puts("--> Ma nay da ton tai. Hay nhap ma khac! <--");
			}
			else {
				// nhập mã nhân viên:
				char staffId[20];
				printf("%s", "Nhap ma nv: ");
				scanf("%*c%19[^\n]", staffId);
				int checkStaffExist =
					findStaffById(staffs, numOfStaff, staffId);
				if (checkStaffExist == -1) {
					puts("--> Nhan vien nay khong co trong danh sach <--");
					break; // ket thuc
				}
				// nhập mã công việc
				int workId;
				printf("%s", "Nhap ma cong viec: ");
				scanf("%d", &workId);
				int checkWorkExist =
					findWorkById(works, numOfWork, workId);
				if (checkWorkExist == -1) {
					puts("--> Cong viec nay khong co trong danh sach <--");
					break; // ket thuc
				}
				// kiểm tra nv đã có mặt trong bảng chấm công của ngày x chưa
				char date[40]; // ngay lam viec
				printf("%s", "Nhap ngay lam viec(dd/mm/yyyy): ");
				scanf("%*c%19[^\n]", date);
				int checkExisted =
					findTimeSheetByDate(sheets,
						numOfTimeSheet, staffId, date);
				if (checkExisted == -1) {
					sheets[numOfTimeSheet].id = id; // gán mã bảng cc, nv, cv
					sheets[numOfTimeSheet].staff = staffs[checkStaffExist];
					sheets[numOfTimeSheet].work = works[checkWorkExist];
					strcpy(sheets[numOfTimeSheet].date, date); 
					// nhập thông tin các đầu điểm còn lại
					createTimeSheetInfo(&sheets[numOfTimeSheet++]);
				}
				else {
					puts("--> Nhan vien nay da ton tai! <--");
				}
			}
			break;
		}
		case 6:
		{	// tính tổng số giờ làm việc thực tế cho từng nv trong tháng
			system("cls");
			calculateWH(sheets, numOfTimeSheet);
			if (numOfTimeSheet > 0) {
				showTimeSheetInfo(sheets, numOfTimeSheet);
			}
			break;
		}
		case 7:
		{	// hiển thị bảng chấm công
			system("cls");
			if (numOfTimeSheet > 0) {
				showTimeSheetInfo(sheets, numOfTimeSheet);
			}
			else {
				puts("--> Danh sach rong! <--");
			}
			break;
		}
		case 8:
		{	// xóa bản ghi trong bảng chấm công
			system("cls");
			int id;
			printf("%s", "Nhap ma bang cham cong can xoa: ");
			scanf("%d", &id);
			removeTimeSheetRecord(sheets, &numOfTimeSheet, id);
			if (numOfTimeSheet > 0) {
				showTimeSheetInfo(sheets, numOfTimeSheet);
			}
			break;
		}
		case 9:
		{
			system("cls");
			calculIncome(sheets, numOfTimeSheet);
			if (numOfTimeSheet > 0) {
				showTimeSheetInfo(sheets, numOfTimeSheet);
			}
			break;
		}
		case 10:
		{
			system("cls");
			sortTimeSheetByIncome(sheets, numOfTimeSheet);
			if (numOfTimeSheet > 0) {
				showTimeSheetInfo(sheets, numOfTimeSheet);
			}
			break;
		}
		case 11:
		{
			int id;
			printf("%s", "Nhap ma bang cham cong can cap nhat: ");
			scanf("%d", &id);
			updateTimeSheet(sheets, numOfTimeSheet, id);
			break;
		}
		case 12:
		{
			system("cls");
			writeFileStaff(staffs, numOfStaff);
			writeFileWork(works, numOfWork);
			writeFileTimeSheet(sheets, numOfTimeSheet);
			break;
		}
		default:
			system("cls"); // xóa màn hình
			puts("--> Vui long chon cac chuc nang tu 0 - 12 <--");
			break;
		}
		puts(""); // in xuống dòng
	} while (choice != 0);
	return 0;
}