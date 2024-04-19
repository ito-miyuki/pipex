#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    // 存在しないファイルを開こうとする
    fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        // perror を使ってエラーメッセージを出力する
        perror("ファイルを開く際にエラーが発生しました");
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
