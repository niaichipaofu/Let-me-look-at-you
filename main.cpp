
#include"_Uart.h"
#include"Matrix.h"

#include<string.h>

struct frameHeaderStructType
{
	uint64_t sync;
	uint32_t version;
	uint32_t platform;
	uint32_t timestamp;
	uint32_t packetLength;
	uint32_t frameNumber;
	uint32_t subframeNumber;
	uint32_t chirpMargin;
	uint32_t frameMargin;
	uint32_t uartSentTime;
	uint32_t trackProcessTime;
	uint16_t numTLVs;
	uint16_t checksum;

}frameheader;

struct tlvHeaderStruct
{
	uint32_t type;
	uint32_t length;

}tlv;

struct pointStruct
{
	float range;
	float angle;
	float doppler;
	float snr;
}point;

struct targetStruct
{
	uint32_t tid;
	float posX;
	float posY;
	float velX;
	float velY;
	float accX;
	float accY;
	float EC;
	float G;
}target;


struct frameStatStruct
{
	uint32_t targetFrameNum;
	struct frameHeaderStructType header;
	int start;
	long bytes;
}fhist[100];

int main(void)
{

	Matrix_tool tool;
	uint64_t magicBytes = 506660481457717506;
	Uart__ Lader("COM4");
	Lader.Uart_init_();
	Lader.Uart_write_lader();
	Lader.~Uart__();

	Uart__ lader("COM5", 921600);
	lader.Uart_init_();
	Matrix_ pointcloud, posall, posall_x, posall_y, snrall;
	Matrix_ TID, s, EC, G;
	long dataLength = 0;
	int offset = 0;
	static int frameHeaderLengthInBytes = 52;
	static int tlvHeaderLengthInBytes = 8;
	static int pointLengthInBytes = 16;
	static int targetLengthInBytes = 68;
	const int indexLengthInBytes = 1;
	char str[1024];
	char p[1000];
	int valueLength = 0, numInputPoints = 0;
	int numTargets = 0, numIndices = 0;
	while (lader.Uart_isConnected_())
	{
	again:	lader.Uart_Read_lader(str);
		memcpy(&frameheader, str, frameHeaderLengthInBytes);
		//lader.Uart_write_file(str);
		if (magicBytes != frameheader.sync)
		{
			printf("Sync error\n");
			goto again;
		}

		dataLength = frameheader.packetLength - frameHeaderLengthInBytes;
		fhist[0].bytes = dataLength;
		lader.Uart_Read_lader(str, dataLength);
		offset = 0;
		for (int i = 0; i < frameheader.numTLVs; i++)
		{
			memcpy(&tlv, &(str[offset]), tlvHeaderLengthInBytes);
			if (tlv.length + offset > dataLength)
			{
				printf("TLV Size is wrong\n");
				goto again;
			}
			offset = offset + tlvHeaderLengthInBytes;
			valueLength = tlv.length - tlvHeaderLengthInBytes;
			switch (tlv.type)
			{
			case 6:
			{
				numInputPoints = valueLength / pointLengthInBytes;
				if (numInputPoints)
				{
					memcpy(&p, &str[offset], valueLength);
					pointcloud = tool._get_Stringmatrix(p, 4, numInputPoints);

					posall_x = tool._get_appointmatrix(pointcloud, 1);
					posall = tool._get_appointmatrix(pointcloud, 2);
					posall = tool._zonmnolinematrix(posall);
					posall_x = tool._dotmulsMatrix(posall_x, posall);
					posall_y = tool._get_appointmatrix(pointcloud, 1);
					posall = tool._get_appointmatrix(pointcloud, 2);
					posall = tool._zonmnolinematrix(posall, 2);
					posall_y = tool._dotmulsMatrix(posall_y, posall);
					posall = tool._splicingvector(posall_x, posall_y);

					snrall = tool._get_appointmatrix(pointcloud, 4);
				}
				//tool._printmatrix(pointcloud);
			//	printf("\n");
				//tool._printmatrix(posall);
				offset = offset + valueLength;
			}break;
			case 7:
			{
				numTargets = valueLength / targetLengthInBytes;
				TID = tool._get_zeroMatrix(1, numTargets);
				s = tool._get_zeroMatrix(6, numTargets);
				EC = tool._get_zeroMatrix(9, numTargets);
				G = tool._get_zeroMatrix(1, numTargets);

				for (int i = 0; i < numTargets; i++)
				{
					memcpy(&p, &str[offset], 68);
					tool._get_appointStrmatrix(TID, p, 1, i, 3, 'u');
					tool._get_appointStrmatrix(s, &p[4], 0, i, 6, 'f');
					tool._get_appointStrmatrix(EC, &p[28], 0, i, 9, 'f');
					tool._get_appointStrmatrix(G, &p[64], 1, i, 1, 'f');
					offset = offset + 68;
				}
				printf("\n\r [目标在X维的位置为 %f m  ]\n", s[0][0]);
				printf("\r [目标在Y维的位置为 %f m  ]\n", s[1][0]);
				printf("\r [目标在X维的速度为 %f m/s  ]\n", s[2][0]);
				printf("\r [目标在Y维的速度为 %f m/s  ]\n", s[3][0]);
				printf("\r [目标在X维的加速度为 %f m/s2  ]\n", s[4][0]);
				printf("\r [目标在Y维的加速度为 %f m/s2  ]\n", s[5][0]);

			}break;
			case 8:
			{

				numIndices = valueLength / indexLengthInBytes;
				offset = offset + valueLength;
			}
			default:
				break;
			}
		}
		//lader.Uart_write_file(str);
		//Sleep(200);
	}
	lader.~Uart__();
}