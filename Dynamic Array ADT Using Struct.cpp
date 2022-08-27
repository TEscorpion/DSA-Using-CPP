#include <iostream>

/* General Functions */
int GenerateRandomNumber(int From, int To) {
	int Rand = rand() % (To - From + 1) + From;

	return Rand; 
}

void Swap(int& A, int& B) {
	int temp;
	temp = A; 
	A = B;
	B = temp; 
}

/* Using Struct */
struct Array {
	int *A = nullptr; 
	int Capacity = 0;
	int Size = 0; 
};

void ReadArrayCapacity(Array& arr) {

	do {
		std::cout << "Please enter the array capacity: ";
		std::cin >> arr.Capacity; 
	} while (arr.Capacity <= 0); 
}

void InitializeArray(Array& arr) {
	arr.A = new int[arr.Capacity]; 
}

void ReadArraySize(Array &arr) {
	do {
		std::cout << "\nPlease enter the number of elements you want: ";
		std::cin >> arr.Size; 
	} while (arr.Size > arr.Capacity || arr.Size < 0); 
}

void Display(Array arr) {
	std::cout << "\nArray elements:\n";
	for (int i = 0; i < arr.Size; i++) {
		std::cout << arr.A[i] << " ";
	}
	std::cout << "\n";
}

void FillArrayWithRandomNumbers(Array& arr) {
	for (int i = 0; i < arr.Size; i++) {
		arr.A[i] = GenerateRandomNumber(1, 100);
	}
}

void ReadArrayElements(Array& arr) {
	std::cout << "\nPlease enter all the elements:\n"; 
	for (int i = 0; i < arr.Size; i++) {
		std::cout << "Please enter element [" << i + 1 << "]: "; 
		std::cin >> arr.A[i]; 
	}
}

void Add(Array &arr, int Number) {
	std::cout << "\nAdd " << Number << " to the array\n";
	if (arr.Size < arr.Capacity) {
		std::cout << "Array size before adding: " << arr.Size << "\n";
		arr.A[arr.Size] = Number;
		arr.Size++;
		std::cout << "Element " << Number << " is added successfully\n"; 
		std::cout << "Array size after adding: " << arr.Size << "\n";
	}
	else {
		std::cout << "Array capacity is: " << arr.Capacity << "\n";
		std::cout << "Array size is: " << arr.Size << "\n"; 
		std::cout << "Sorry, The capacity of the array is full.\n"; 
	}
}

void Insert(Array& arr, int index, int Number) {
	std::cout << "\nInsert " << Number << " at index " << index << "\n"; 

	if (arr.Size < arr.Capacity) {
		std::cout << "Array size before insertion: " << arr.Size << "\n";
		
		for (int i = arr.Size; i > index; i--) {
			arr.A[i] = arr.A[i - 1]; 
		}
		arr.A[index] = Number;
		arr.Size++; 

		std::cout << "Element " << Number << " is inserted successfully at index " << index << "\n";
		std::cout << "Array size after insertion: " << arr.Size << "\n";
	}
	else {
		std::cout << "Array capacity is: " << arr.Capacity << "\n";
		std::cout << "Array size is: " << arr.Size << "\n";
		std::cout << "Sorry, The capacity of the array is full.\n";
	}
}

void Delete(Array& arr, int index) {
	std::cout << "\nDelete index " << index << "\n"; 
	std::cout << "Array size before deletion is " << arr.Size << "\n";
	for (int i = index; i < arr.Size - 1; i++) {
		arr.A[i] = arr.A[i + 1]; 
	}
	arr.Size--; 
	std::cout << "Index " << index << " deleted successfully\n";
	std::cout << "Array size after deletion is " << arr.Size << "\n";
}

int Search(Array& arr, int Number) {
	std::cout << "\nSearch for number " << Number << "\n";

	for (int i = 0; i < arr.Size; i++) {
		if (arr.A[i] == Number) {
			std::cout << Number << " is found at index " << i << "\n";
			return i; 
		}
	}

	std::cout << Number << " is NOT found" << "\n"; 
}

int Get(Array &arr, int index) {
	std::cout << "\nElement at index " << index << " is: "; 
	return arr.A[index]; 
}

void Set(Array& arr, int index, int Number) {
	std::cout << "\nSet " << Number << " at index " << index << "\n"; 

	if (index >= 0 && index < arr.Size) {
		arr.A[index] = Number;
		std::cout << Number << " set successfully at index " << index << "\n"; 
	}
	else {
		std::cout << "Sorry, Invalid index\n"; 
	}
}

int Max(Array& arr) {
	std::cout << "\nMax of the array is: "; 
	int Max = arr.A[0]; 

	for (int i = 1; i < arr.Size; i++) {
		if (arr.A[i] > Max) {
			Max = arr.A[i];
		}
	}

	return Max; 
}

int Min(Array& arr) {
	std::cout << "\nMin of the array is: ";
	int Min = arr.A[0];

	for (int i = 1; i < arr.Size; i++) {
		if (arr.A[i] < Min) {
			Min = arr.A[i];
		}
	}

	return Min;
}

float Average(Array& arr) {
	std::cout << "\nAverage of the array is: ";
	int Sum = 0; 

	for (int i = 0; i < arr.Size; i++) {
		Sum += arr.A[i];
	}

	return (float)Sum / arr.Size;
}

void Reverse(Array& arr) {
	std::cout << "\nReverse Array\n";
	
	for (int i = 0, j = arr.Size - 1; i < j; i++, j--) {
		Swap(arr.A[i], arr.A[j]); 
	}
	std::cout << "Array Reversed Successfully\n"; 
}

void Rotate(Array& arr) {
	std::cout << "\nRotate Array\n"; 
	int temp = arr.A[0];
	for (int i = 0; i < arr.Size-1; i++) {
		arr.A[i] = arr.A[i + 1]; 
	}
	arr.A[arr.Size - 1] = temp; 
	std::cout << "Array rotated successfully\n";
}

int main() {
	srand((unsigned)time(NULL)); 

	Array arr; 
	ReadArrayCapacity(arr);
	InitializeArray(arr); 
	ReadArraySize(arr); 

	FillArrayWithRandomNumbers(arr);
	Display(arr); 

	Insert(arr, 3, 4); 
	Display(arr);

	Delete(arr, 2); 
	Display(arr);

	std::cout << Get(arr, 2) << "\n";

	Set(arr, 2, 44); 
	Display(arr);

	std::cout << Max(arr) << "\n";
	std::cout << Min(arr) << "\n";
	std::cout << Average(arr) << "\n";

	Reverse(arr);
	Display(arr);

	Rotate(arr);
	Display(arr);
}