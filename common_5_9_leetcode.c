#define  _CRT_SECURE_NO_WARNINGS
35. 搜索插入位置
int BSearch(int arr[], int n, int tar)
{
	int l = 0, r = n - 1;
	int ans = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (tar <= arr[mid])
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}
int searchInsert(int* nums, int numsSize, int target)
{
	int ret = BSearch(nums, numsSize, target);
	return ret;
}

704. 二分查找
int BSearch(int arr[], int n, int tar)
{
	int l = 0, r = n - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (tar<arr[mid])
		{
			r = mid - 1;
		}
		else if (tar == arr[mid])
		{
			ans = mid;
			break;
		}
		else
			l = mid + 1;

	}
	return ans;
}
int search(int* nums, int numsSize, int target){
	int ret = BSearch(nums, numsSize, target);
	return ret;
}

剑指 Offer 53 - I.在排序数组中查找数字 I
int BSearch(int arr[], int n, int tar)
{
	int l = 0, r = n - 1;
	int ans = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (tar <= arr[mid])
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}
int search(int* nums, int numsSize, int target){
	int ret = BSearch(nums, numsSize, target);
	int ret2 = BSearch(nums, numsSize, target + 1);
	return ret2 - ret;
}

911. 在线选举
#define maxn 5001
typedef struct {
	int p[maxn], t[maxn], win[maxn];
	int cnt[maxn];
	int size;
} TopVotedCandidate;


TopVotedCandidate* topVotedCandidateCreate(int* persons, int personsSize, int* times, int timesSize) {
	TopVotedCandidate* obj = (TopVotedCandidate*)malloc(sizeof(TopVotedCandidate));
	int preMaxPerson = -1;
	memset(obj->cnt, 0, sizeof(obj->cnt));
	for (int i = 0; i<personsSize; i++)
	{
		obj->p[i] = persons[i];
		obj->t[i] = times[i];
		++obj->cnt[obj->p[i]];
		if (preMaxPerson == -1 || obj->cnt[obj->p[i]] >= obj->cnt[preMaxPerson])
			preMaxPerson = obj->p[i];
		obj->win[i] = preMaxPerson;
	}
	obj->size = personsSize;
	return obj;
}

int topVotedCandidateQ(TopVotedCandidate* obj, int t) {
	int l = 0, r = obj->size - 1;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (t >= obj->t[mid])
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return obj->win[ans];
}

void topVotedCandidateFree(TopVotedCandidate* obj) {
	free(obj);
	obj = NULL;
}

