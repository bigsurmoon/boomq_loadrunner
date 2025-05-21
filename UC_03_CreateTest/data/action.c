Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("DNT", 
		"1");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"136\", \"Microsoft Edge\";v=\"136\", \"Not.A/Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("authorize", 
		"URL=https://dev-boomq.pflb.ru/authorize", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2025-05-21T12:10:35.408Z");

	lr_think_time(11);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=nagruzka3_gr01@mail.com", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=25", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC_03_TR_02_create_test");

	lr_end_transaction("UC_03_TR_02_create_test",LR_AUTO);

	lr_start_transaction("UC_03_TR_03_edit_test");

	lr_end_transaction("UC_03_TR_03_edit_test",LR_AUTO);

	lr_start_transaction("UC_03_TR_04_edit_transaction");

	lr_end_transaction("UC_03_TR_04_edit_transaction",LR_AUTO);

	lr_start_transaction("UC_03_TR_05_save_changes");

	lr_end_transaction("UC_03_TR_05_save_changes",LR_AUTO);

	lr_start_transaction("UC_03_TR_07_load_profile");

	lr_end_transaction("UC_03_TR_07_load_profile",LR_AUTO);

	lr_start_transaction("UC_03_TR_08_sla");

	lr_end_transaction("UC_03_TR_08_sla",LR_AUTO);

	lr_start_transaction("UC_03_TR_09_save_test");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"hadouken_test_666\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"2e6ba5cb-5c2c-4df6-bd3e-8d7a1ed15cc3\",\"label\":\"random_test\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\"\",\""
		"threadGroupElements\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"GET\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"/WebTours/\",\"port\":\"\",\"protocol\":\"https\",\"search\":\"?\",\"serverName\":\"webtours.pflb.ru\",\"headers\":{},\"queryParameters\":[],\"body\":\"\",\"bodyParameters\":[]},\"timerList\":["
		"],\"label\":\"https://webtours.pflb.ru/WebTours/\",\"id\":\"630e7d5f-b1f7-4615-8b25-0b6310978da1\",\"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"random_transaction_666\",\"id\":\"ab427d86-711c-49dd-b889-7ae727e22e53\",\"type\":\"CONTROLLER\",\"enabled\":true,\""
		"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"849abd4a-5b42-45e6-9e26-06d70f7c7727\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\""
		"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"2d0bd16e-ab3e-431d-ada1-c0b3aeda93cc\",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"4d07b174-e300-4af7-a0d0-ca0c908cb535\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":1,\"rampDownMs\":0,\"durationAddedOnLastStepMs\":0,\"boomqProfileType\":\"STABLE\",\"rampUpMs\":0,\"stepLengthMs\""
		":60000,\"stepCount\":1},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_ae0b691a-2e9b-42ae-8902-248db1443de2\",\"id\":\"ae0b691a-2e9b-42ae-8902-248db1443de2\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[{\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":46,\"value\":\"123\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\""
		"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":53,\"value\":\"33\"}]},{\"type\":\"THREAD_GROUP_SLA\",\"targetType\":\"THREAD_GROUP\",\"slaList\":[{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":54,\"value\":\"778\"}],\"threadGroupId\":\"2e6ba5cb-5c2c-4df6-bd3e-8d7a1ed15cc3\",\"threadGroupName\":\"random_test\"},{\"type\":\"TRANSACTION_SLA\",\"targetType\":\"TRANSACTION\",\"transactionId\":\""
		"ab427d86-711c-49dd-b889-7ae727e22e53\",\"transactionName\":\"random_transaction_666\",\"slaList\":[{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":51,\"value\":\"6\"}],\"threadGroupId\":null,\"threadGroupName\":null},{\"type\":\"REQUEST_SLA\",\"targetType\":\"REQUEST\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\",\"slaList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\","
		"\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":53,\"value\":\"7\"}],\"threadGroupId\":null,\"threadGroupName\":null}],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":60}", 
		EXTRARES, 
		"Url=../static/media/check.9725c0396328bae9471b624111fc14ca.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	lr_end_transaction("UC_03_TR_09_save_test",LR_AUTO);

	return 0;
}