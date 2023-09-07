#include<iostream>
#include<string>
using namespace std;


string digit(int angka_digit){
	string satuan[] = {"Nol", "Satu", "Dua", "Tiga", 
	"Empat", "Lima", "Enam", 
	"Tujuh", "Delapan", "Sembilan"};
	return satuan[angka_digit];
}

string convert(int num){
	if(num >= 0 && num < 10){
		return digit(num);
	}else if (num >= 10 && num < 20){
		string belasan[] = {"Sepuluh","Sebelas", "Duabelas",
		"Tigabelas", "Empatbelas",
		"Limabelas","Enambelas","Tujuhbelas","Delapanbelas",
		"Sembilanbelas"};
		return belasan[num-10];
	}else if(num >= 20 && num <100){
		int angka_depan = num/10;
		int angka_belakang = num%10;
		string hasil = digit(angka_depan) + " Puluh";
		if (angka_belakang > 0){
			hasil += " " + digit(angka_belakang);
		}
		return hasil;
	}else if(num >= 100 && num < 1000){
		int angka_depan = num/100;
		int angka_belakang = num % 100;
		string hasil;
		if(angka_depan == 1){
			hasil = digit(angka_depan) = "Seratus";
		}else{
		hasil = digit(angka_depan) + " Ratus";
	}
		if(angka_belakang > 0){
			hasil += " " + convert(angka_belakang);
		}
		return hasil;
	}else if(num >= 1000 && num < 1000000){
		
		int angka_depan = num / 1000;
		int angka_belakang = num % 1000;
		string hasil;
		if(angka_depan == 1){
			hasil = digit(angka_depan) = "Seribu";
		}else{
		hasil = convert(angka_depan) + " Ribu";
	}
		if(angka_belakang > 0){
			hasil += " " + convert(angka_belakang);
		}
		return hasil;
	}else if(num >= 1000000 && num < 1000000000){
		int angka_depan = num / 1000000;
		int angka_belakang = num % 1000000;
		string hasil = convert(angka_depan) + " Juta";
		if(angka_belakang > 0){
			hasil += " " + convert(angka_belakang);
		}
		return hasil;
	}
	
	return "Angka Melebihi Kapasitas";
}




int main(){
	int angk;
	char k;
	do{
		system("cls");
	cout<<"Masukkan Angka : ";
	cin>>angk;
	cout<<convert(angk)<<" Rupiah"<<endl;
	cout<<"Ulang (Y/N) : ";
	cin>>k;	
	}while(k == 'Y' || k == 'y');
	
	cout<<"Program Berakhir"<<endl;
	
	
}
