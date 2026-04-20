/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 02 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Beatrice Corryn Pangestu (13224038)
 *   Nama File           : soal1.c
 *   Deskripsi           : Di sebuah stasiun pengamatan cuaca ekstrem, deretan sensor badai mengirimkan data intensitas angin 
 * secara berkala. Sayangnya, beberapa pembacaan hilang akibat gangguan transmisi dan ditandai 
sebagai data kosong. Sebelum data tersebut dipakai oleh tim analisis, sistem harus terlebih dahulu 
memulihkan nilai yang hilang berdasarkan pembacaan valid terdekat. Setelah seluruh data 
dipulihkan, tim ingin mengetahui rentang waktu pengamatan paling berbahaya, yaitu segmen kontigu 
dengan total intensitas terbesar.  
Pulihkan elemen array yang hilang lalu cari jumlah subarray maksimum.
 * 
 */

 #include <stdio.h>
 void cek(int *angka,int jumlah){
    int max;
    if (jumlah==1){
        if (*angka== -1){
            *angka=0;
        }  
    }
    if (*angka == -1){
        int i=1;
        while (*angka == -1){
            if (*(angka+i) != -1){
                *angka= *(angka+i);
            }else{
                i++;
            }
        }
    }
    for (int i=1; i<jumlah;i++){
        int n=i+1;
        if (n <jumlah){
            while (*(angka+i)== -1){
                if (*(angka+n)!= -1 ){
                    if((*(angka+i-1)+*(angka+n))%2 !=0 && (*(angka+i-1)+*(angka+n))<0){
                        *(angka+i)= (*(angka+i-1)+*(angka+n)-1)/2;
                    }else{
                    *(angka+i)= (*(angka+i-1)+*(angka+n))/2;
                    }
                    
                    
                }else if (*(angka+n)==-1 && n==jumlah-1){
                    *(angka+i)= *(angka+i-1);
                }
            }
            if (*(angka+jumlah-1)== -1){
                *(angka+jumlah-1)=*(angka+jumlah-2);
            }
            n++;
        }
    }
    int curr;
    curr= 0;
    max= *angka;
    for (int i=0; i<jumlah;i++){
        if (curr+*(angka+i)>*(angka+i)){
            curr= curr + *(angka+i);
        }else{
            curr= *(angka+i);
        }
        if(curr> max){
            max = curr;
        }
    }
    printf("\nRECOVERED ");
    for (int i=0; i<jumlah;i++){
        printf("%d",*(angka+i));
        if (i<jumlah-1){
            printf(" ");
        }
    }
    printf("\nMAX_SUM %d",max);
 }
 int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    int *ptr= arr;
    for (int i=0; i<N;i++){
        scanf("%d",(ptr+i));
    }
    cek(ptr,N);
 }
