int peserta(int N, vector<vector<int>> C){
    // N merupakan jumlah stage
    
    // C[i][j] merupakan tenaga yang diperlukan untuk memindahkan
    // pemain dari stage i ke stage j dengan i < j
    
    int gura = 1;
    int gawr = 1;
    int sum_gura = 0;
    int sum_gawr = 0;
    
    for(int pos = 2; pos <= N; ++pos){
        if(sum_gura + C[gura][pos] < sum_gawr + C[gawr][pos]){
            sum_gura += C[gura][pos];
            gura = pos;
        } else {
            sum_gawr += C[gawr][pos];
            gawr = pos;
        }
    }
    
    return sum_gura + sum_gawr;
}