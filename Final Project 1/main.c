#include <stdio.h>
#include <string.h>
#include "student.h"
#include "subject.h"
#include "transcript.h"

/*
* @author Branium Academy
*/

int main()
{
	Transcript trans[200];
	Subject subjects[100];
	Student students[200];
	size_t numOfTrans = 0;
	size_t numOfStudent = 0;
	size_t numOfSubject = 0;
	// đọc file khi chương trình khởi động
	readFileStudent(students, &numOfStudent);
	readFileSubject(subjects, &numOfSubject);
	readFileTrans(trans, &numOfTrans);

	int choice;
	do {
		puts("============== QUAN LY BANG DIEM ==============");
		puts("01. Them moi mon hoc vao danh sach");
		puts("02. Hien thi danh sach mon hoc");
		puts("03. Them moi sinh vien vao danh sach");
		puts("04. Hien thi danh sach sinh vien");
		puts("05. Tao bang diem cho mot sinh vien");
		puts("06. Tinh diem tong ket va xep loai sinh vien");
		puts("07. Hien thi thong tin bang diem");
		puts("08. Sap xep bang diem giam dan theo diem TK");
		puts("09. Tim sv co diem TK bang y trong bang diem");
		puts("10. Tim sv co xep loai y trong bang diem");
		puts("11. Cap nhat cac dau diem theo ma bang diem");
		puts("12. Ghi danh sach tai khoan vao file");
		puts("0. Thoat chuong trinh");
		printf("Xin moi chon: ");
		scanf("%d", &choice);
		printf("============== Chuc nang so %d ==============\n", choice);

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
		{
			// nhập thêm môn học mới
			int id;
			printf("%s", "Nhap ma mon: ");
			scanf("%d", &id);
			// kiểm tra xem môn học có mã id này đã tồn tại chưa
			int index = findSubjectById(subjects, numOfSubject, id);
			if (index != -1) {
				puts("--> Mon hoc nay da ton tai. Hay nhap ma khac! <--");
			}
			else {
				subjects[numOfSubject].id = id;
				// nhập các thông tin còn lại của môn học
				getSubjectInfo(&subjects[numOfSubject]);
				numOfSubject++;
			}
			break;
		}
		case 2:
		{
			system("cls"); // xóa màn hình
			if (numOfSubject > 0) {
				showSubjects(subjects, numOfSubject);
			}
			else {
				puts("--> Danh sach rong! <--");
			}			
			break;
		}
		case 3:
		{
			system("cls");
			char id[20];
			printf("%s", "Nhap ma SV: ");
			scanf("%*c%19[^\n]", id);
			// kiểm tra xem sv có mã id này đã tồn tại chưa
			int index = findStudentById(students, numOfStudent, id);
			if (index != -1) {
				puts("--> Sv nay da ton tai. Hay nhap ma khac! <--");
			}
			else {
				strcpy(students[numOfStudent].id, id);
				// nhập các thông tin còn lại của sv
				getStudentInfo(&students[numOfStudent]);
				numOfStudent++;
			}
			break;
		}
		case 4:
		{
			system("cls");
			if (numOfStudent > 0) {
				showStudentsInfo(students, numOfStudent);
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
			printf("%s", "Nhap ma bang diem: ");
			scanf("%d", &id);
			int index = findTransById(trans, numOfTrans, id);
			if (index != -1) {
				puts("--> Ma nay da ton tai. Hay nhap ma khac! <--");
			}
			else {
				// nhập mã sinh viên:
				char studentId[20];
				printf("%s", "Nhap ma sv: ");
				scanf("%*c%19[^\n]", studentId);
				int checkStudentExist = 
					findStudentById(students, numOfStudent, studentId);
				if (checkStudentExist == -1) {
					puts("--> Sinh vien nay khong co trong danh sach <--");
					break; // ket thuc
				}
				// nhập mã môn học
				int subjectId;
				printf("%s", "Nhap ma mon hoc: ");
				scanf("%d", &subjectId);
				int checkSubjectExist = 
					findSubjectById(subjects, numOfSubject, subjectId);
				if (checkSubjectExist == -1) {
					puts("--> Mon hoc nay khong co trong danh sach <--");
					break; // ket thuc
				}
				// kiểm tra sinh viên và môn học này đã có chưa
				int checkExisted = 
					findTranByStudentSubjectId(trans, 
						numOfTrans, studentId, subjectId);
				if (checkExisted == -1) {
					trans[numOfTrans].id = id; // gán mã bảng điểm, sv, mh
					trans[numOfTrans].student = students[checkStudentExist];
					trans[numOfTrans].subject = subjects[checkSubjectExist];
					// nhập thông tin các đầu điểm còn lại
					getTranscriptInfo(&trans[numOfTrans++]);
				}
				else {
					puts("--> Sinh vien nay da ton tai! <--");
				}
			}
			break;
		}
		case 6:
		{
			system("cls");
			calculFinalGrade(trans, numOfTrans);
			classify(trans, numOfTrans);
			if (numOfTrans > 0) {
				showTranscript(trans, numOfTrans);
			}
			break;
		}
		case 7:
		{
			system("cls");
			if (numOfTrans > 0) {
				showTranscript(trans, numOfTrans);
			}
			else {
				puts("--> Danh sach rong! <--");
			}
			break;
		}
		case 8:
		{
			system("cls");
			sortByFinalGrade(trans, numOfTrans);
			if (numOfTrans > 0) {
				showTranscript(trans, numOfTrans);
			}
			break;
		}
		case 9:
		{
			system("cls");
			Transcript result[100]; // giả sử mảng kq lưu đc tối đa 100 p.tử
			float x;
			printf("%s", "Nhap diem can tim: ");
			scanf("%f", &x);
			// tim kiem
			size_t numOfResult = 
				findStudentByFinalGrade(trans, numOfTrans, result, x);
			if (numOfResult == 0) {
				puts("--> Khong co ket qua <--");
			}
			else {
				showTranscript(result, numOfResult);
			}
			break;
		}
		case 10:
		{
			system("cls");
			Transcript result[100]; // giả sử mảng kq lưu đc tối đa 100 p.tử
			char classif[10];
			printf("%s", "Nhap xep loai muon tim(Vi du A, A+): ");
			scanf("%*c%9s", classif);
			// tim kiem
			size_t numOfResult = 
				findStudentByClassif(trans, numOfTrans, result, classif);
			if (numOfResult == 0) {
				puts("--> Khong co ket qua <--");
			}
			else {
				showTranscript(result, numOfResult);
			}
			break;
		}
		case 11:
		{
			int id;
			printf("%s", "Nhap ma bang diem can cap nhat diem: ");
			scanf("%d", &id);
			int index = findTransById(trans, numOfTrans, id);
			if (index == -1) {
				puts("--> Ma nay khong ton tai. Hay nhap ma khac! <--");
			}
			else {
				int res = updateById(trans, numOfTrans, id);
				if (res) {
					puts("--> Cap nhat diem thanh cong! <--");
				}
			}
			break;
		}
		case 12:
		{
			system("cls");
			writeFileStudent(students, numOfStudent);
			writeFileSubject(subjects, numOfSubject);
			writeFileTrans(trans, numOfTrans);
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
