#include "sortiranja.h"

// KOLEKICJA ALGORITAMA ZA SORTIRANJE //

// *** Sortiranje biranjem ***
void selection_sort(int A[], int N) {
	for (int i = 0; i < N - 1; i++) {
		int ind = i;
		for (int j = i + 1; j < N; j++)
			if (A[ind] > A[j]) ind = j;
		if (ind != i) { // zamjena
			int tmp = A[i];
			A[i] = A[ind];
			A[ind] = tmp;
		}
	}
}

// *** Bubble sort ***
void bubble_sort(int A[], int N) {
	int i, j, BilaZamjena;
	for (i = 0, BilaZamjena = 1; BilaZamjena; i++) {
		BilaZamjena = 0;
		for (j = 0; j < N - 1 - i; j++) {
			if (A[j + 1] < A[j]) {
				// Zamijeni (&A[j], &A[j+1]); 
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				BilaZamjena = 1;
			}
		}
	}
}

// *** InsertionSort ***
void insertion_sort(int A[], int N) {
	int i, j;
	int pom;
	for (i = 1; i < N; i++) {
		pom = A[i];
		for (j = i; j >= 1 && A[j - 1] > pom; j--)
			A[j] = A[j - 1];
		A[j] = pom;
	}
}

// *** ShellSort ***
void shell_sort(int A[], int N) {
	int i, j, korak, pom;
	for (korak = N / 2; korak > 0; korak /= 2) {
		for (i = korak; i < N; i++) {
			pom = A[i];
			for (j = i; j >= korak && A[j - korak] > pom; j -= korak) {
				A[j] = A[j - korak];
			}
			A[j] = pom;
		}
	}
}

// *** MergeSort *** 
// spajanje dva podniza u jedan niz
void Merge(int* array, int* tmp, int lpos, int rpos, int rend) {
	int i, lend, n, k;

	lend = rpos - 1;
	k = lpos;

	n = rend - lpos + 1;
	// Sve dok jedno od polja ne ostane bez elemenata, radi ...
	while (lpos <= lend && rpos <= rend) {
		// ako je element lijevog podpolja manji od desnog, uzmi njega,
		if (array[lpos] < array[rpos])
			tmp[k++] = array[lpos++];
		// inace uzmi element desnog podpolja
		else
			tmp[k++] = array[rpos++];
	}
	// Sada je sigurno jedno od polja ostalo bez elemenata, pa
	// ako u lijevom jos ima nesto, to sve prekopiraj ...
	while (lpos <= lend) {
		tmp[k++] = array[lpos++];
	}
	// ili mozda u desnom ima jos nesto pa to sve prekopiraj
	// treba uočiti da se neće izvršiti obje while petlje jer je
	// jedno polje sigurno ostalo bez elemenata!
	while (rpos <= rend) {
		tmp[k++] = array[rpos++];
	}
	// i konačno prekopiraj tih n elemenata natrag u originalno polje
	for (i = 0; i < n; i++, rend--)
		array[rend] = tmp[rend];
}

//rekurzivni merge sort
void MergeRecursive(int* array, int* tmp, int left, int right) {
	int middle;

	// ako polje ima više od jednog elementa, radi ...
	if (left < right) {
		// nađi sredinu
		middle = (left + right) / 2;
		// rekurzivno sortiraj podpolje nastalo od prvog indeksa do srednjeg
		MergeRecursive(array, tmp, left, middle);
		// rekurzivno sortiraj podpolje nastalo 
		// od srednjeg indeksa + 1 do zadnjeg indeksa
		MergeRecursive(array, tmp, middle + 1, right);
		// i spoji ta dva podpolja
		Merge(array, tmp, left, middle + 1, right);
	}
}

//glavna funkcija - merge
void merge_sort(int* array, int n) {
	int* tmp;

	tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL) return; // greska!
	MergeRecursive(array, tmp, 0, n - 1);
	free(tmp);
}

// *** HeapSort *** //
//smjestanje cvora u stablu na tocnu poziciju
void Podesi(int* array, int n, int i) {
	int j;
	int t;

	// Izracunaj indeks lijevog djeteta
	j = 2 * i + 1;
	// Zapamti vrijednost korijena (tj. element koji kvari strukturu)
	t = array[i];
	// Tako dugo dok se nismo spustili do dna strukture, radi ...
	while (j < n) {
		// ako desno dijete postoji, i ako je veće od lijevog, tada
		// neka j postane indeks desnog djeteta
		if (j < n - 1 && array[j] < array[j + 1]) j++;
		// ako veće dijete nije veće od roditelja, prekid!
		if (t >= array[j]) break;
		// Inače treba popraviti strukturu. Zato u roditelja kopiramo veće dijete,
		// a u veće dijete bismo trebali roditelja: t, no ako će i ispod trebati
		// mijenjati, onda smo bezveze kopirali pa to ne radimo već pamtimo da je to t.
		// Ujedno proglašavamo veće dijete roditeljem, i računamo indeks njegove djece.
		array[i] = array[j]; i = j; j = 2 * j + 1;
	}
	// sada konačno stavljamo ovu zapamćenu vrijednost na mjesto bivšeg većeg djeteta.
	array[i] = t;
}

//stvaranje stabla
void StvoriGomilu(int* array, int n) {
	int i;

	for (i = (n - 2) / 2; i >= 0; i--)
		Podesi(array, n, i);
}

//glavna funkcija - heap
void heap_sort(int* array, int n) {
	int i;
	int t;

	StvoriGomilu(array, n);
	for (i = n; i >= 2; i--) {
		t = array[i - 1]; array[i - 1] = array[0]; array[0] = t;
		Podesi(array, i - 1, 0);
	}
}

// *** QuickSort *** //
void quick_sort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

void quick_sort(int arr[], int n) {
	quick_sort(arr, 0, n - 1);
}

// POMOCNE FUNKCIJE

//generira slucajni broj tipa long int
int lrand(int n)
{
	return (rand() * (RAND_MAX + 1) + rand()) % (n + 1);
}

//razlika izmedju dva vremena u ms
double diffclock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
}

//puni polje slucajnim long brojevima
void napuni_polje_rand(int* polje, int n)
{
	for (int i = 0; i < n; i++)
		polje[i] = lrand(n); //generira slucajni broj 0 do RAND_MAX
}

//puni polje sa brojevima od 1..n
void napuni_polje_az(int* polje, int n)
{
	for (int i = 0; i < n; i++)
		polje[i] = i + 1;
}

//puni polje sa brojevima od n..1
void napuni_polje_za(int* polje, int n)
{
	for (int i = 0; i < n; i++)
		polje[i] = n - i;
}

//ispisi polje
void ispisi_polje(int* polje, int n)
{
	for (int i = 0; i < n; i++)
		cout << polje[i] << "\t";
	cout << endl << endl;
}
