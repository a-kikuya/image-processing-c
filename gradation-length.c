#include <stdio.h>
#include <math.h>

/*
縦にグラデーション
参考 ra: http://image.onishi-lab.jp/001.html
*/

int main(void)
{
	int x, y, i= 0;
	double a = 480.0, b = 640.0;
	unsigned int color = 0;
	unsigned char image[480][640][3]; //unsigned char型　保存できる値　0-255
	//三次元配列 データ型 配列名[要素数1][要素数2][要素数3];
	FILE *fp;
	fp = fopen("gradation.pbm", "wb");
	fprintf(fp, "P6\n640 480\n255\n"); //ヘッダにテキストを書き込み
	//fprintf(ファイルポインタ,書き込み文字列,変数);
	
	for(y = 0; y < a; y++){
		for(x = 0; x < 640; x++){
			if(x < 640){
				color = floor(((255 - 0) *(640.0 - y) / 640.0) + 0.5); //四捨五入で整数
			} else {
				color = 255;
			}
			image[y][x][0] = image[y][x][1] = image[y][x][2] = color;
		}
		color = 0;
	}
	fwrite(image, sizeof(char), 640*480*3,fp); //データ(数値)の書き込み
	//fwrite(書き込む変数アドレス,1項目のサイズ,項目数,ファイルポインタ);
	fclose(fp); 
}
	
	