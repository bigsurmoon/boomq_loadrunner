vuser_init()
{
	char email[100];
    char displayName[50];
    char change_pass_url[1024];
    int randNum;

    srand((unsigned int)time(NULL));

    randNum = 100 + rand() % 900;

    sprintf(displayName, "Test_%d", randNum);
    sprintf(email, "test_%d@hadouken.com", randNum);
    sprintf(change_pass_url, "");

    lr_save_string(displayName, "displayName");
    lr_save_string(email, "email");
    lr_save_string(change_pass_url, "change_pass_url");
    
	return 0;
}
