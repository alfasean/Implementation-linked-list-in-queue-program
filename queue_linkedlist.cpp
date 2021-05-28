#include<iostream>
using namespace std;

struct data{
	string namaPemain;
	string posisiPemain;
	int noPemain;
};

class simpul{
	public :
		data datapemain;
		simpul *pBerikutnya;
			
		simpul(string nP,string poP, int np){
			datapemain.namaPemain = nP;
			datapemain.posisiPemain = poP;
			datapemain.noPemain = np;
			pBerikutnya = NULL;
		}
		
		void tampilSimpul()	{
			cout << "                            " << datapemain.noPemain << "--->" << datapemain.namaPemain << "--->" << datapemain.posisiPemain<< endl;
		}
};

class linkedlist {
	private :
		simpul *pPertama;
		simpul *pAkhir;
	
	public :
		linkedlist() : pPertama(NULL) 
		{}
		
		bool isEmpty(){
			return (pPertama==NULL); 
		}
		
		void sisipAkhir(string nP, string poP, int np) {
			simpul *pSimpulBaru  = new simpul(nP,poP,np);
			if(isEmpty()) {
				pPertama = pSimpulBaru; 
			}
			 else {
				pAkhir->pBerikutnya = pSimpulBaru;
			}
			pAkhir = pSimpulBaru;
		}

		void hapusPertama() {
			simpul *pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
    		delete pTemp;
		}
		
		void tampilSenarai() {
			simpul *pSekarang = pPertama;
			if(pSekarang==NULL) {
				cout << "                                DATA MASIH KOSONG" << endl;
			}
			else {
			while(pSekarang!=NULL) {
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
		    	}
			}
		}
};

class queuelist {
	private :
		linkedlist *pSenarai; 
	
	public :
		queuelist() {
			pSenarai = new linkedlist; 
		}
		
		void push(string nP, string poP, int np) {
			pSenarai->sisipAkhir(nP,poP,np);
		}
		
		void pop() {
			pSenarai->hapusPertama();	
		}
		
		bool isEmpty() {
			return (pSenarai->isEmpty());
		}
		
		void tampildata(){
			cout << "                       ===|DATA INPUTAN KE DALAM QUEUE|===" << endl;
			pSenarai->tampilSenarai();
			cout << "           ------------------------------------------------------------" << endl;
		}
};

int main() {
	queuelist queue;
	int pilih, no;
	string nama, posisi;
	do {
     	system("cls");
		cout << "                        ===================================" << endl;
      	cout << "                        NAMA : ALFA SEAN KALAPADANG LONTENG" << endl;
      	cout << "                        NIM  : 20101106067" << endl;
      	cout << "                        ===================================" << endl;
      	cout << "\n           ============================================================" << endl;
      	cout << "           ||                         PROGRAM                        ||" << endl;
      	cout << "	   ||	               DATA PEMAIN SEPAK BOLA                ||" << endl;
      	cout << "           ============================================================" << endl;
      	queue.tampildata();
		cout << "                              ========|MENU|======== " << endl;
		cout << "                              ======================" << endl;
		cout << "                                1. ENQUEUE" << endl;
		cout << "                                2. DEQUEUE" << endl;
		cout << "                                3. EXIT" << endl;
		cout << "                              ======================" << endl;
		cout << "                                => PILIH MENU : ";
		cin >> pilih;
		cout << "           ============================================================" << endl;
		switch(pilih){
			case 1 :
				cout << "                => MASUKKAN NOMOR PUNGGUNG PEMAIN : "; cin >> no;
				cin.ignore(256,'\n');
				cout << "                => MASUKKAN NAMA PEMAIN   : "; getline(cin,nama);
				cout << "                => MASUKKAN POSISI PEMAIN : "; getline(cin,posisi);
				queue.push(nama,posisi,no);
				break;
				
			case 2 :
				if (queue.isEmpty() == 0){
				queue.pop();
			    }
			    else {
			    	cout << "                       =>DATA PADA QUEUE MASIH KOSONG!!!"<<endl;
				}
				break;
			
			case 3 :
				exit(0);
				break;
				
			default :
				cout << "                       => PILIHAN YANG ANDA MASUKKAN SALAH!!!"<<endl;
		}
		system ("pause");
	} while (true);
	return 0;
}
