vuser_init()
{
	char reportName[50];
	char paragraph_text[50];
	char list_item_1[50], list_item_2[50], list_item_3[50];
	char report_name[50];
	char body[2048];

	char table_cell_1[30], table_cell_2[30], table_cell_3[30];
	char table_cell_4[30], table_cell_5[30], table_cell_6[30];

	int randNum;
	int rnd_paragraph, rnd_list1, rnd_list2, rnd_list3, rnd_report;
	int t1, t2, t3, t4, t5, t6;

	srand((unsigned int)time(NULL));

	randNum = 100 + rand() % 900;
	rnd_paragraph = 100 + rand() % 900;
	rnd_list1 = 100 + rand() % 900;
	rnd_list2 = 100 + rand() % 900;
	rnd_list3 = 100 + rand() % 900;
	rnd_report = 100 + rand() % 900;

	t1 = 100 + rand() % 900;
	t2 = 100 + rand() % 900;
	t3 = 100 + rand() % 900;
	t4 = 100 + rand() % 900;
	t5 = 100 + rand() % 900;
	t6 = 100 + rand() % 900;

	sprintf(reportName, "hadouken_%d", randNum);
	sprintf(report_name, "hadouken_%d", rnd_report);
	sprintf(paragraph_text, "group_3_%d", rnd_paragraph);

	sprintf(list_item_1, "random_%d", rnd_list1);
	sprintf(list_item_2, "random_%d", rnd_list2);
	sprintf(list_item_3, "random_%d", rnd_list3);

	sprintf(table_cell_1, "random_%d", t1);
	sprintf(table_cell_2, "random_%d", t2);
	sprintf(table_cell_3, "random_%d", t3);
	sprintf(table_cell_4, "random_%d", t4);
	sprintf(table_cell_5, "random_%d", t5);
	sprintf(table_cell_6, "random_%d", t6);

	sprintf(body,
		"{\"labelSet\":[],\"name\":\"%s\",\"testIdSet\":[],"
		"\"reportContent\":{\"charts\":[],\"reportMarkup\":\""
		"[{\\\"id\\\":\\\"Sc91y_bCi2\\\",\\\"type\\\":\\\"paragraph\\\",\\\"data\\\":{\\\"text\\\":\\\"%s\\\"}},"
		"{\\\"id\\\":\\\"kBeLWSoZB4\\\",\\\"type\\\":\\\"list\\\",\\\"data\\\":{\\\"style\\\":\\\"unordered\\\","
		"\\\"items\\\":[\\\"%s\\\",\\\"%s\\\",\\\"%s\\\"]}},"
		"{\\\"id\\\":\\\"YugbtKOd1c\\\",\\\"type\\\":\\\"table\\\",\\\"data\\\":{\\\"withHeadings\\\":false,"
		"\\\"content\\\":[[\\\"%s\\\",\\\"%s\\\",\\\"%s\\\"],"
		"[\\\"%s\\\",\\\"%s\\\",\\\"%s\\\"]]}}]\","
		"\"tables\":[]}}",
		report_name,
		paragraph_text,
		list_item_1, list_item_2, list_item_3,
		table_cell_1, table_cell_2, table_cell_3,
		table_cell_4, table_cell_5, table_cell_6
	);

	lr_save_string(body, "body");
	lr_save_string(reportName, "reportName");

	return 0;
}