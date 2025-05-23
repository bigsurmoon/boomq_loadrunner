vuser_init()
{
	int trendNum = rand() % 99 + 1;
	char trendName[64];
	char threadGroupName[64];
	sprintf(trendName, "hadouken_trend_%d", trendNum);
	sprintf(threadGroupName, "hadouken_tread_%d", threadGroupName);
	lr_save_string(trendName, "trendName");
	lr_save_string(threadGroupName, "threadGroupName");
	return 0;
}
