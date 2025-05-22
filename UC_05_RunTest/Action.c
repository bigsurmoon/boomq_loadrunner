Action()
{
	lr_start_transaction("UC_05_TR_GLOBAL");
	
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_url("authorize", 
		"URL=https://dev-boomq.pflb.ru/authorize", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML",  
		LAST);
	
	lr_start_transaction("UC_05_TR_01_sign_in");

	web_add_header("Origin", "https://dev-boomq.pflb.ru");

	web_set_max_html_param_len("4096");
	
	web_reg_save_param("auth_token",
     	"LB=boomq_auth=",
     	"RB=;",
     	"Search=Headers",
     	"Ordinal=1",
    	LAST);
    
	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={user}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
	lr_output_message("========= TOKEN =========: %s", lr_eval_string("{auth_token}"));
	
	web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token}"));
	
	web_add_cookie("boomq_auth={auth_token}; DOMAIN=dev-boomq.pflb.ru");
	
	web_reg_save_param_json(
		"ParamName=teamId", 
		"QueryString=$..id", 
		SEARCH_FILTERS, 
		"Scope=Body", 
		LAST);
    
    web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param(
        "auth_token_new",
        "LB=set-cookie: boomq_auth=",
        "RB=\r\n",
        "Search=Headers",
        LAST);
	
	web_url("team_context", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_header("Cookie",  lr_eval_string("boomq_auth={auth_token_new}; boomq_auth={auth_token}"));
	
    web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token_new}"));

	lr_end_transaction("UC_05_TR_01_sign_in",LR_AUTO);

	lr_start_transaction("UC_05_TR_02_open_tests_page");

	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json(
		"ParamName=projectId",
		"QueryString=$..projectId",
		SEARCH_FILTERS,
		LAST);

	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_05_TR_02_open_tests_page",LR_AUTO);

	lr_start_transaction("UC_05_TR_03_click_run_button");
	
	web_reg_save_param_json(
		"ParamName=versionId", 
		"QueryString=$..version..id", 
		SEARCH_FILTERS, 
		"Scope=Body", 
		LAST);

	web_url("project_id", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{projectId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{projectId}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("version_id", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{projectId}/version/{versionId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{projectId}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("downloadLink", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{projectId}/version/{versionId}/downloadLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{projectId}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/minio/boomq/boomq/teams/22/projects/2543/v_3581.yaml?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIOSFODNN7EXAMPLE/20250522/us-east-1/s3/aws4_request&X-Amz-Date=20250522T132651Z&X-Amz-Expires=604800&X-Amz-SignedHeaders=host&X-Amz-Signature=5cb5effba98a03efa8f7f340e3a175642173379a8e755e668f502c3a0b2656b1", "Referer=https://dev-boomq.pflb.ru/account/tests/2543", ENDITEM, 
		LAST);

	lr_end_transaction("UC_05_TR_03_click_run_button",LR_AUTO);

	lr_start_transaction("UC_05_TR_04_run_tests");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{projectId}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"labelSet\":[],\"projectId\":\"{projectId}\",\"projectVersionId\":{versionId},\"testMode\":\"TEST\",\"testProjectId\":\"{projectId}\",\"testProjectVersionId\":{versionId}}", 
		LAST);

	lr_end_transaction("UC_05_TR_04_run_tests",LR_AUTO);
	
	lr_end_transaction("UC_05_TR_GLOBAL",LR_AUTO);

	return 0;
}