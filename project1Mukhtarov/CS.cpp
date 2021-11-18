#include "pch.h"
#include "CS.h"

void CS::set_id(int id_) {
	CS::id = id_;
}
int CS::get_id() {
	return CS::id;
}
void CS::set_count_of_CS(int count_of_CS_) {
	CS::count_of_CS = count_of_CS_;
}
int CS::get_count_of_CS() {
	return CS::count_of_CS;
}
void CS::set_count_of_CS_in_work(int count_of_CS_in_work_) {
	CS::count_of_CS_in_work = count_of_CS_in_work_;
}
int CS::get_count_of_CS_in_work() {
	return CS::count_of_CS_in_work;
}
void CS::set_name_CS(std::string name_CS_) {
	CS::name_CS = name_CS_;
}
std::string CS::get_name_CS() {
	return CS::name_CS;
}