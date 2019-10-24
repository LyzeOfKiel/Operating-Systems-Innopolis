#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dirp = opendir("./tmp");
    struct dirent *dp;

    char *name[255];
    ino_t inode_n[255];
    
    int i = 0;

    while ((dp = readdir(dirp)) != NULL) {
        inode_n[i] = dp->d_ino;
        name[i] = dp->d_name;
        i++;
    }
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (inode_n[k] == inode_n[j] && inode_n[k] != 0) {
                printf("Linked files %s, %s\n", name[j], name[k]);
                inode_n[k] = 0;
            }
        }
    }
    closedir(dirp);
    return 0;
}