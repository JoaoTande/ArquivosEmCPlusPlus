#include <iostream>
#include <fstream>
using namespace std;

int main() {
	streampos size;
	char * memblock;
	unsigned char memblock2;
	unsigned char memblock3[4];
	ofstream ArqSaida;
	ArqSaida.open("ArquivoSaidaInvertidoCorreto.bin", ios::binary);
	
	printf("  ");
	ifstream file("Dump128.bin", ios::in | ios::binary | ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char[size];
		file.seekg(0, ios::beg);
		file.read(memblock, size);
		file.close();

		/*for (int i = 1; i < 720; i++){
			memblock2 = memblock[i-1];
			printf("%.2X ", memblock2);
			if ((i % 16 == 0) && (i != 0)){
				printf("\n");
			}
			if ((i % 8 == 0) && (i != 0)){
				printf("  ");
			}
		}*/


		for (int i = 0; i < size; i = i + 4){
			memblock3[0] = memblock[i];
			memblock3[1] = memblock[i + 1];
			memblock3[2] = memblock[i + 2];
			memblock3[3] = memblock[i + 3];

			ArqSaida << memblock3[3];
			ArqSaida << memblock3[2];
			ArqSaida << memblock3[1];
			ArqSaida << memblock3[0];

			/*printf("%.2X %.2X %.2X %.2X ", memblock3[0], memblock3[1], memblock3[2], memblock3[3]);
			if ((i % 16 == 0) && (i != 0)){
				printf("\n");
			}

			if ((i % 8 == 0) && (i != 0)){
				printf("  ");
			}*/

		}

		cout << "the entire file content is in memory";
		ArqSaida.close();
		delete[] memblock;
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}
