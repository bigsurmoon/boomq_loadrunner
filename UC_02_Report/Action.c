Action()
{
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

	lr_start_transaction("UC_02_TR_01_sign_in");

	web_add_header("Origin", "https://dev-boomq.pflb.ru");

	lr_think_time(5);

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
		"ParamName=user_id",
		"QueryString=$.id",
		SEARCH_FILTERS,
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param(
        "auth_token_new",
        "LB=set-cookie: boomq_auth=",
        "RB=\r\n",
        "Search=Headers",
        LAST);
	
	web_url("team_context", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=25", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_02_TR_01_sign_in",LR_AUTO);

	lr_start_transaction("UC_02_TR_02_click_on_reports");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(5);
	
	web_add_header("Cookie",  lr_eval_string("boomq_auth={auth_token_new}; boomq_auth={auth_token}"));
	
    web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token_new}"));

	web_custom_request("search", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"pagination\":{\"pageNumber\":0,\"pageSize\":9},\"sort\":[{\"field\":\"CREATED_AT\",\"direction\":\"DESC\"}]}", 
		LAST);

	lr_end_transaction("UC_02_TR_02_click_on_reports",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC_02_TR_03_add_report");

	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=FINISHED", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/new", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_02_TR_03_add_report",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("UC_02_TR_04_save_report");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(5);
	
	web_custom_request("report", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/new", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={body}", 
		LAST);

	lr_end_transaction("UC_02_TR_04_save_report",LR_AUTO);

	return 0;
}