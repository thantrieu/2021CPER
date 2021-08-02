// thuật toán sắp xếp trộn đệ quy
void mergeSort(arr[], firt, last) { // first, last: chỉ số phần tử đầu, cuối
    if(first < last) {              // nếu first nhỏ hơn last
        middle = (first + last)/2;  // tìm chỉ số phần tử giữa
        mergeSort(arr, first, middle); // sắp xếp trộn nửa đầu mảng
        mergeSort(arr, middle + 1, last); // sắp xếp trộn nửa sau mảng
        merge(arr, first, middle, last);  // trộn hai nửa đã sắp xếp
    }
}

// thuật toán trộn hai mảng đã sắp xếp tăng dần
void merge(arr[], first, middle, last) {
    // xác định kích thước hai mảng con cần trộn
    size1 = middle - first + 1; // kích thước mảng con trái
    size2 = last - middle; // kích thước mảng con phải
    // tạo mảng con để lưu các phần tử để trộn
    leftArr[] = new T[size1];
    rightArr[] = new T[size2];
    // chép dữ liệu vào mảng con trái
    for(i = 0; i < size1; i++) {
        leftArr[i] = arr[l + i];
    }
    // chép dữ liệu vào mảng con phải
    for(j = 0; j < size2; j++) {
        rightArr[j] = arr[middle + j];
    }
    // tiến hành trộn
    i = 0; j = 0; k = first;
    while(i < size1 && j < size2) {
        if(leftArr[i] <= rightArr[j]) { 
            // gán arr[k] = leftArr[i] sau đó tăng k, i
            arr[k++] = leftArr[i++]; 
        } else {
            arr[k++] = rightArr[j++]; // gán sau đó tăng k, j
        }
    }
    // chép các phần tử còn lại của mảng trái vào mảng arr
    while(i < size1) {
        arr[k++] = leftArr[i++];
    }
    // chép các phần tử còn lại của mảng phải vào mảng arr
    while(j < size2) {
        arr[k++] = rightArr[j++];
    }
}
