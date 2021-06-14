unsigned int stringToInt(char* key) // 글자 Key를 정수로 바꿔주는 역할
{
	int number = 0;
	while (*key) {
		number += *key++;
	}
	return number;
}

int h(unsigned int k) { // Division
	return k % b;
}

int s(int i) // Random Probing
{
	return random[i];
}

void insertht(int k, char data[]) {
	int homeBucket, currentBucket;
	element* temp;
	homeBucket = h(k);

	MALLOC(temp, sizeof(element) * s);

	for (currentBucket = homeBucket; ht[currentBucket];)
	{
		currentBucket = (currentBucket + 1) % b;

		if (currentBucket == b)
		{
			printf("exit\n");
			return;
		}
	}

	strcpy_s(temp->item, LEN, data);
	temp->key = k;

	ht[currentBucket] = temp;
}

element* search(int k)
{
	int homeBucket, currentBucket;
	homeBucket = h(k);
	cnt = 1;


	for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;) {
		cnt++;

		currentBucket = (currentBucket + 1) % b;

		if (currentBucket == homeBucket)
			return NULL;
	}
	if (ht[currentBucket] && ht[currentBucket]->key == k)
		return ht[currentBucket];

	return NULL;
}


// Chaining 의 경우

int stringToInt(char* item)
{
	int num = 0;

	while (*item)
		num += *item++;

	return num;
}

void insertht(nodePointer x)
{
	nodePointer temp;
	int index = h(x->data.key);

	if (!ht[index].link)
		ht[index].link = x;

	else
	{
		for (temp = ht[index].link; temp; temp = temp->link)
		{
			if (!temp->link)
			{
				temp->link = x;
				break;
			}
		}
	}
}

element* search(int k)
{
	nodePointer current;
	cnt = 1;

	current = ht[h(k)].link;
	for (; current; current = current->link)
	{
		if (current->data.key == k)
			return &current->data;
		cnt++;
	}

	return NULL;
}