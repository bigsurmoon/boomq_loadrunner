vuser_init()
{
	char email[100];
    char displayName[50];
    int randNum;

    srand((unsigned int)time(NULL));

    randNum = 100 + rand() % 900;

    sprintf(displayName, "Test_%d", randNum);
    sprintf(email, "test_%d@hadouken.com", randNum);

    lr_save_string(displayName, "displayName");
    lr_save_string(email, "email");
    
	return 0;
}
