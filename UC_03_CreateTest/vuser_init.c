vuser_init()
{
	char projectName[50];
	char testRequestName[50];
	char transactionName[50];
	char body[16000];

	int projectNameRandom;
	int testRequestNameRandom;
	int transactionNameRandom;

	srand((unsigned int)time(NULL));

	projectNameRandom = 1000 + rand() % 9000;
	testRequestNameRandom = 100 + rand() % 900;
	transactionNameRandom = 100 + rand() % 900;

	sprintf(projectName, "hadouken_test_%d", projectNameRandom);
	sprintf(testRequestName, "random_test_%d", testRequestNameRandom);
	sprintf(transactionName, "transaction_%d", transactionNameRandom);

	lr_save_string(projectName, "projectName");
	lr_save_string(testRequestName, "testRequestName");
	lr_save_string(transactionName, "transactionName");

	sprintf(body,
		"{\n"
		"  \"comment\":\"\",\n"
		"  \"contentFormat\":\"yaml\",\n"
		"  \"contentModelVersion\":\"2.0.0\",\n"
		"  \"labelSet\":[],\n"
		"  \"requestCount\":1,\n"
		"  \"testType\":\"STABLE\",\n"
		"  \"projectName\":\"%s\",\n"
		"  \"contentV2\":{\n"
		"    \"boomqTestPlan\":{\n"
		"      \"threadGroups\":[{\n"
		"        \"boomqConfiguration\":{\n"
		"          \"resourceConfiguration\":{},\n"
		"          \"loadProfilePercent\":100\n"
		"        },\n"
		"        \"enabled\":true,\n"
		"        \"id\":\"2e6ba5cb-5c2c-4df6-bd3e-8d7a1ed15cc3\",\n"
		"        \"label\":\"%s\",\n"
		"        \"steps\":[],\n"
		"        \"type\":\"BOOMQ_STABLE_SCALABILITY\",\n"
		"        \"typeDisplayName\":\"\",\n"
		"        \"threadGroupElements\":[{\n"
		"          \"children\":[{\n"
		"            \"children\":\"\",\n"
		"            \"individualProperties\":{\n"
		"              \"useKeepAlive\":true,\n"
		"              \"type\":\"HTTP\",\n"
		"              \"retrieveAllEmbeddedResources\":true,\n"
		"              \"followRedirects\":true,\n"
		"              \"automaticallyRedirect\":false,\n"
		"              \"method\":\"GET\",\n"
		"              \"browserCompatibleHeaders\":false,\n"
		"              \"doMultipartPost\":false,\n"
		"              \"path\":\"/WebTours/\",\n"
		"              \"port\":\"\",\n"
		"              \"protocol\":\"https\",\n"
		"              \"search\":\"?\",\n"
		"              \"serverName\":\"webtours.pflb.ru\",\n"
		"              \"headers\":{},\n"
		"              \"queryParameters\":[],\n"
		"              \"body\":\"\",\n"
		"              \"bodyParameters\":[]\n"
		"            },\n"
		"            \"timerList\":[],\n"
		"            \"label\":\"https://webtours.pflb.ru/WebTours/\",\n"
		"            \"id\":\"630e7d5f-b1f7-4615-8b25-0b6310978da1\",\n"
		"            \"type\":\"SAMPLER\",\n"
		"            \"enabled\":true,\n"
		"            \"assertions\":[],\n"
		"            \"extractors\":[],\n"
		"            \"typeDisplayName\":\"HTTP Request\"\n"
		"          }],\n"
		"          \"individualProperties\":{\n"
		"            \"includeDurationOfAllElementsToGeneratedSampler\":false,\n"
		"            \"generateParentSampler\":false,\n"
		"            \"type\":\"TRANSACTION\"\n"
		"          },\n"
		"          \"timerList\":[],\n"
		"          \"label\":\"%s\",\n"
		"          \"id\":\"ab427d86-711c-49dd-b889-7ae727e22e53\",\n"
		"          \"type\":\"CONTROLLER\",\n"
		"          \"enabled\":true,\n"
		"          \"creationIndex\":1,\n"
		"          \"typeDisplayName\":\"Transaction Controller\"\n"
		"        }]\n"
		"      }],\n"
		"      \"runThreadGroupConsecutively\":false,\n"
		"      \"loadProfileType\":\"PER_TEST\",\n"
		"      \"functionalMode\":false,\n"
		"      \"runTearDownAfterShutdown\":true,\n"
		"      \"configurationElements\":[{\n"
		"        \"clearControlledByThreadGroup\":false,\n"
		"        \"cookiePolicy\":\"STANDARD\",\n"
		"        \"clearEachIteration\":false,\n"
		"        \"userDefinedCookies\":[],\n"
		"        \"label\":\"Http cookie manager\",\n"
		"        \"id\":\"849abd4a-5b42-45e6-9e26-06d70f7c7727\",\n"
		"        \"type\":\"HTTP_COOKIE_MANAGER\",\n"
		"        \"enabled\":true\n"
		"      },{\n"
		"        \"headers\":{\n"
		"          \"User-Agent\":\"Mozilla/5.0\"\n"
		"        },\n"
		"        \"label\":\"Http header manager\",\n"
		"        \"id\":\"2d0bd16e-ab3e-431d-ada1-c0b3aeda93cc\",\n"
		"        \"type\":\"HTTP_HEADER_MANAGER\",\n"
		"        \"enabled\":true\n"
		"      },{\n"
		"        \"label\":\"Http request defaults\",\n"
		"        \"type\":\"HTTP_REQUEST_DEFAULTS\",\n"
		"        \"enabled\":true,\n"
		"        \"id\":\"4d07b174-e300-4af7-a0d0-ca0c908cb535\",\n"
		"        \"connectTimeout\":60000,\n"
		"        \"responseTimeout\":120000\n"
		"      }],\n"
		"      \"loadProfile\":{\n"
		"        \"usersPerStep\":1,\n"
		"        \"rampDownMs\":0,\n"
		"        \"durationAddedOnLastStepMs\":0,\n"
		"        \"boomqProfileType\":\"STABLE\",\n"
		"        \"rampUpMs\":0,\n"
		"        \"stepLengthMs\":60000,\n"
		"        \"stepCount\":1\n"
		"      },\n"
		"      \"timers\":[{\n"
		"        \"timerType\":\"CONSTANT\",\n"
		"        \"label\":\"boomq_timer_ae0b691a-2e9b-42ae-8902-248db1443de2\",\n"
		"        \"id\":\"ae0b691a-2e9b-42ae-8902-248db1443de2\",\n"
		"        \"durationMs\":8000,\n"
		"        \"enabled\":true\n"
		"      }]\n"
		"    },\n"

		// SLA

		"    \"slaGroupList\": [\n"
		"      {\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":60,\"value\":\"123\"},{\"fromDate\":0,\"restrictionType\":\"ERROR_RATE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":60,\"value\":\"33\"}]},\n"
		"      {\"type\":\"THREAD_GROUP_SLA\",\"targetType\":\"THREAD_GROUP\",\"slaList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":60,\"value\":\"778\"}],\"threadGroupId\":\"2e6ba5cb-5c2c-4df6-bd3e-8d7a1ed15cc3\",\"threadGroupName\":\"%s\"},\n"
		"      {\"type\":\"TRANSACTION_SLA\",\"targetType\":\"TRANSACTION\",\"transactionId\":\"ab427d86-711c-49dd-b889-7ae727e22e53\",\"transactionName\":\"%s\",\"slaList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":60,\"value\":\"6\"}],\"threadGroupId\":null,\"threadGroupName\":null},\n"
		"      {\"type\":\"REQUEST_SLA\",\"targetType\":\"REQUEST\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\",\"slaList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":60,\"value\":\"7\"}],\"threadGroupId\":null,\"threadGroupName\":null}\n"
		"    ],\n"
		"    \"supportingFiles\":[],\n"
		"    \"supportingFilesV2\":[]\n"
		"  },\n"
		"  \"totalDuration\":60\n"
		"}\n",
		projectName,
		testRequestName,
		transactionName,
		testRequestName,
		transactionName
	);

	lr_save_string(body, "body");

	return 0;
}