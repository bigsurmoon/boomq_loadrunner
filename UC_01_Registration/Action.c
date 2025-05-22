Action()
{
	
	lr_start_transaction("UC_01_GLOBAL_TRANSACTION");
	
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
	
	lr_start_transaction("UC_01_TR_01_sign_in");

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
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_01_sign_in",LR_AUTO);
	
	lr_start_transaction("UC_01_TR_02_click_on_group");
	
	web_url("teams", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?page=0&size=5", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_02_click_on_group",LR_AUTO);

	lr_start_transaction("UC_01_TR_03_edit_group");

	web_url("team_number", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Cookie",  lr_eval_string("boomq_auth={auth_token_new}; boomq_auth={auth_token}"));
	
    web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token_new}"));

	lr_end_transaction("UC_01_TR_03_edit_group",LR_AUTO);
	
	lr_start_transaction("UC_01_TR_04_add_member");
	
	web_reg_save_param_json(
		"ParamName=inviteUrl",
		"QueryString=$..inviteUrl",
		SEARCH_FILTERS,
		LAST);
	
	web_custom_request("add_member", 
    	"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22", 
    	"Method=POST", 
    	"TargetFrame=", 
    	"Resource=0", 
    	"RecContentType=application/json", 
    	"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
    	"Snapshot=t7.inf", 
    	"Mode=HTML", 
    	"EncType=application/json", 
    	"Body=[{\"email\":\"{email}\",\"permissionList\":[\"VIEW\",\"EDIT\",\"RUN\"],\"userDisplayName\":\"{displayName}\"}]", 
    	LAST);
	
	lr_output_message("========= INVITE URL =========: %s", lr_eval_string("{inviteUrl}"));
	
	web_cleanup_auto_headers();
	
    web_cleanup_cookies();

	lr_end_transaction("UC_01_TR_04_add_member",LR_AUTO);
	
	lr_start_transaction("UC_01_TR_05_invite_url");
	
	lr_save_string(lr_eval_string("https://dev-boomq.pflb.ru{inviteUrl}"), "change_pass_url");

    web_reg_save_param("auth_token_cookie", 
    	"LB=set-cookie: boomq_auth=", 
    	"RB=;", 
    	"Search=Headers", 
    	LAST);
	
	web_url("invite_url", 
		"URL={change_pass_url}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
    
    web_add_auto_header("Authorization", "Bearer {auth_token_cookie}");
	
	lr_end_transaction("UC_01_TR_05_invite_url", LR_AUTO);
	
	lr_start_transaction("UC_01_TR_06_change_password");
	
	web_add_header("Content-Type", "application/json");

	web_custom_request("change_password", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/change-password", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"Body={\"password\":\"{password}\"}", 
		LAST);

	lr_end_transaction("UC_01_TR_06_change_password",LR_AUTO);
	
	lr_end_transaction("UC_01_GLOBAL_TRANSACTION",LR_AUTO);
	
	return 0;
}