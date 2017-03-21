#pragma once
#pragma warning(disable: 4996)

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

}

#include <io.h>
#include <time.h>
//#include <queue>
#include <cliext/queue>
//#include <thread>

namespace CLRproj {

	using namespace System::Runtime::InteropServices;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace cliext;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			av_register_all();
			InitializeBackgoundWorker();

			//
			//TODO: Add the constructor code here
			//
		}

	private:
		void InitializeBackgoundWorker()
		{
			backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			backgroundWorker1->ProgressChanged += gcnew ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;
	protected:

	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  tbOpenFilePath;
	private: System::Windows::Forms::Button^  btnProcces;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::RichTextBox^  rtbVideoInfo;
	private: System::Windows::Forms::ProgressBar^  pbProccess;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::ListView^  lvVideoInfo;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;









		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tbOpenFilePath = (gcnew System::Windows::Forms::TextBox());
			this->btnProcces = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->rtbVideoInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->pbProccess = (gcnew System::Windows::Forms::ProgressBar());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->lvVideoInfo = (gcnew System::Windows::Forms::ListView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(684, 364);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(112, 23);
			this->btnExit->TabIndex = 0;
			this->btnExit->Text = L"Выход";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(684, 10);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(112, 23);
			this->btnOpen->TabIndex = 1;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tbOpenFilePath
			// 
			this->tbOpenFilePath->Location = System::Drawing::Point(12, 12);
			this->tbOpenFilePath->Name = L"tbOpenFilePath";
			this->tbOpenFilePath->Size = System::Drawing::Size(648, 20);
			this->tbOpenFilePath->TabIndex = 2;
			// 
			// btnProcces
			// 
			this->btnProcces->Location = System::Drawing::Point(684, 160);
			this->btnProcces->Name = L"btnProcces";
			this->btnProcces->Size = System::Drawing::Size(112, 23);
			this->btnProcces->TabIndex = 3;
			this->btnProcces->Text = L"Анализ";
			this->btnProcces->UseVisualStyleBackColor = true;
			this->btnProcces->Click += gcnew System::EventHandler(this, &MyForm::btnProcces_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Enabled = false;
			this->btnCancel->Location = System::Drawing::Point(684, 189);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(112, 23);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"Отмена";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm::btnCancel_Click);
			// 
			// rtbVideoInfo
			// 
			this->rtbVideoInfo->Enabled = false;
			this->rtbVideoInfo->Location = System::Drawing::Point(12, 68);
			this->rtbVideoInfo->Name = L"rtbVideoInfo";
			this->rtbVideoInfo->Size = System::Drawing::Size(200, 228);
			this->rtbVideoInfo->TabIndex = 5;
			this->rtbVideoInfo->Text = L"";
			// 
			// pbProccess
			// 
			this->pbProccess->Location = System::Drawing::Point(12, 37);
			this->pbProccess->Name = L"pbProccess";
			this->pbProccess->Size = System::Drawing::Size(648, 24);
			this->pbProccess->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			this->pbProccess->TabIndex = 6;
			this->pbProccess->Value = 20;
			this->pbProccess->Visible = false;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(666, 68);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(156, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Рассыпание на квадраты";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(666, 91);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(112, 17);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"Смещение строк";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(666, 114);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(130, 17);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"Статически элемент";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// lvVideoInfo
			// 
			this->lvVideoInfo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader1,
					this->columnHeader2, this->columnHeader3, this->columnHeader4
			});
			this->lvVideoInfo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lvVideoInfo->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lvVideoInfo->Location = System::Drawing::Point(230, 68);
			this->lvVideoInfo->Name = L"lvVideoInfo";
			this->lvVideoInfo->Size = System::Drawing::Size(292, 228);
			this->lvVideoInfo->TabIndex = 10;
			this->lvVideoInfo->UseCompatibleStateImageBehavior = false;
			this->lvVideoInfo->View = System::Windows::Forms::View::Details;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(702, 250);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(702, 279);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 12;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"";
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"";
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 399);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lvVideoInfo);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->pbProccess);
			this->Controls->Add(this->rtbVideoInfo);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnProcces);
			this->Controls->Add(this->tbOpenFilePath);
			this->Controls->Add(this->btnOpen);
			this->Controls->Add(this->btnExit);
			this->Name = L"MyForm";
			this->Text = L"Анализ видео";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		queue<String^> qVideoInfo;
		String^ str;
		Thread^ demoThread;
		Thread^	processThread;
		bool isWorked = true;
		bool error = false;	
		AVFormatContext *pFormatCtx = NULL;
		const int ANYINT = 10;
		String^ pathMat = "materials/";

		char * and_SysStringToChar(System::String^ string) {
			return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
		}	

		void disableUI() {
			btnCancel->Enabled = true;
			btnOpen->Enabled = false;
			btnProcces->Enabled = false;
			//tbOpenFilePath->Enabled = false;
			tbOpenFilePath->ReadOnly = true;
			pbProccess->Visible = true;
		}

		void enableUI() {
			btnCancel->Enabled = false;
			btnOpen->Enabled = true;
			btnProcces->Enabled = true;
			//tbOpenFilePath->Enabled = true;
			tbOpenFilePath->ReadOnly = false;
			pbProccess->Visible = false;
		}

		void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame) {
			FILE *pFile;
			char szFilename[32];
			int  y;
			//AVPicture picture;
			// Open file

			//sprintf(szFilename, "frame%d.bmp", iFrame);
			sprintf(szFilename, "materials/frame%d.ppm", iFrame);
			pFile = fopen(szFilename, "wb");
			if (pFile == NULL)
				return;
			// Write header
			fprintf(pFile, "P6\n%d %d\n255\n", width, height);

			/*cout << "linesize = " << pFrame->linesize[0] << endl;
			cout << "data = " << pFrame->data[0] << endl;*/
			// Write pixel data

			//pFrame->data[0][1] = 255;
			/*
			for (y = 0; y < 3 * width * height; ++y) {
				if ((y % 3) == 0) {
					*(pFrame->data[0] + y) = 255;
				}
			}
			*/
			for (y = 0; y < height; y++)
				fwrite(pFrame->data[0] + y*pFrame->linesize[0], 1, width * 3, pFile);
			/*picture.data;
			picture.linesize;*/

			// Close file
			fclose(pFile);
		}
	
		void SaveDiag(AVFrame *pFrame, int width, int height) {
			FILE *pFile, *pFile2, *txtfile;
			char szFilename[32];
			int  y;



			//txtfile = fopen("allPixels.txt", "wb");
			pFile2 = fopen("materials/test.txt", "wb");
			// Open file

			//sprintf(szFilename, "frame%d.bmp", iFrame);
			//sprintf(szFilename, "diag.ppm");
			//pFile = fopen(szFilename, "wb");
			//if (pFile == NULL)
			//	return;

			// Write header
			//fprintf(pFile, "P6\n%d %d\n255\n", 4, 1);
			//fprintf(pFile, "P6\n%d %d\n255\n", width, height);

			// Write pixel data
			//fwrite(pFrame->data[0] + 315*201+316, 3, 4, pFile);
			//fwrite(pFrame->data[0], 3, 10, pFile2);

			//uint8_t black[] = { 0, 0, 0 };
			//uint8_t white[] = { 255, 255, 255};
			//bool f = 0;
			//for (int e = 0; e < width * height; ++e) {
			//	if (f) {
			//		if (((e % 2) == 0)) {
			//			fwrite(pFrame->data[0] + 3 * e, 3, 1, pFile);
			//		}
			//		else {
			//			fwrite(white, 3, 1, pFile);
			//		}
			//	}
			//	else {
			//		if (((e % 2) == 0)) {
			//			fwrite(white, 3, 1, pFile);
			//		}
			//		else {
			//			fwrite(pFrame->data[0] + 3 * e, 3, 1, pFile);
			//		}
			//	}
			//	if (((e + 1) % width) == 0) {
			//		f = !f;
			//	}
			//}
			//uint8_t *temp;

			//for (int j = 0; j < width * height; ++j) {
			//	temp = pFrame->data[0] + j;
			//	//fprintf(txtfile, (pFrame->data[0] + j));
			//	
			//	for (int k = 0; k < AV_NUM_DATA_POINTERS; ++k) {
			//		fprintf(txtfile, "%d ", int(temp[k]));
			//		if (((j + 1) % 3) == 0) {
			//			fprintf(txtfile, "");
			//		}
			//	}
			//	
			//}

			SaveFrame(pFrame, width, height, 999);

			for (int i = 0; i < 3*width*height; ++i) {
				//temp = pFrame->data[0] + i;
				fprintf(pFile2, "%d	", int(*(pFrame->data[0] + i)));
				/*
				for (int k = 0; k < AV_NUM_DATA_POINTERS; ++k) {
					fprintf(pFile2, "%d	", int(temp[k]));
				}*/
				//fprintf(pFile2, "		");
			}
			int num = 0;
			//fclose(pFile);
			//fclose(txtfile);
			fclose(pFile2);
		}

		void SaveAnalisPix(AVFrame *pFrame, int width, int height) {
			FILE *filePix, *fileRazn, *fileSrednee;
			fileSrednee = fopen("materials/srednee.txt", "wb");
			filePix = fopen("materials/pix.txt", "wb");
			fileRazn = fopen("materials/razn.txt", "wb");

			// Open file
			if ((filePix == NULL) || (fileSrednee == NULL) || (fileRazn == NULL))
				return;

			uint8_t *temp;
			int c = 0;
			for (int j = 0; j < 3 * width * height; ++j) {
				fprintf(filePix, "%d	", int(*(pFrame->data[0] + j)));
				/*temp = pFrame->data[0] + j;
				for (int k = 0; k < 3; ++k) {
					fprintf(filePix, "%d ", int(temp[k]));
					if (((j + 1) % 3) == 0) {
						fprintf(filePix, "");
					}
				}*/
			}

			int** mas;
			mas = new int*[height];
			for (int i = 0; i < height; ++i) {
				mas[i] = new int[width];
			}


			int sum = 0;
			int k = 0;
			for (int i = 0; i < width * height; ++i) {	
				sum += int(*(pFrame->data[0] + i));
				++k;
				if (k == 3) {
					fprintf(fileSrednee, "%5.2f		 ", 1. * sum / 3);
					sum = 0;
					k = 0;
				}
			}

			/*for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j) {
					temp = pFrame->data[0] + i * width + j;
					int sum = 0;
					for (int k = 0; k < 3; ++k) {
						sum += int(temp[k]);
						mas[i][j] = int(temp[k]);
					}
					fprintf(fileSrednee, "%d	", sum / 3);
				}
			}*/

			//for (int i = 0; i < width * height; ++i) {
			//	temp = pFrame->data[0] + i;
			//	int sum = 0;
			//	for (int k = 0; k < 3; ++k) {
			//		//fprintf(fileSrednee, "%d ", int(temp[k]));
			//		sum += int(temp[k]);
			//		mas[c] = int(temp[k]);
			//		++c;
			//	}
			//	fprintf(fileSrednee, "%d	", sum / 3);
			//}


			fclose(filePix);
			fclose(fileSrednee);
			fclose(fileRazn);
		}

		void SaveSrPix(AVFrame *pFrame, int width, int height) {
			FILE *filePix, *fileRazn, *fileSrednee;

			fileSrednee = fopen("srednee.txt", "wb");
			filePix = fopen("pix.txt", "wb");
			fileRazn = fopen("razn.txt", "wb");
			// Open file
			if ((filePix == NULL) || (fileSrednee == NULL) || (fileRazn == NULL))
				return;
			
			uint8_t *temp;
			int c = 0;
			for (int j = 0; j < width * height; ++j) {
				temp = pFrame->data[0] + j;
				for (int k = 0; k < 3; ++k) {
					fprintf(filePix, "%d ", int(temp[k]));
					if (((j + 1) % 3) == 0) {
						fprintf(filePix, "");
					}
				}
			}
			int num = 0;
			
			int mas[100000000];

			
			for (int i = 0; i < width * height; ++i) {
				temp = pFrame->data[0] + i;
				int sum = 0;
				for (int k = 0; k < 3; ++k) {
					//fprintf(fileSrednee, "%d ", int(temp[k]));
					sum += int(temp[k]);
					mas[c] = int(temp[k]);
					++c;
				}
				fprintf(fileSrednee, "%d	", sum / 3);
			}

			
			for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j) {
					fprintf(fileRazn, "%d	", mas[width * i + j] - mas[width * i + j + 1]);
				}
				fprintf(fileRazn, "									");
			}


			fclose(filePix);
			fclose(fileSrednee);
			fclose(fileRazn);
		}
		
		void processVideo(Object^ paramObj) {
			//disableUI();
			//setVideoText("");		
		}
		
		void backgroundWorker1_DoWork(Object^ sender, DoWorkEventArgs^ e)
		{
			// Get the BackgroundWorker that raised this event.
			BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

			pin_ptr<AVFormatContext *> ppFormatCtx = &pFormatCtx;
			if (avformat_open_input(ppFormatCtx, and_SysStringToChar(tbOpenFilePath->Text), NULL, 0) != 0)
			{
				MessageBox::Show("Файл не может быть открыт.");
				error = true;
				return;
			}

			if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
			{
				MessageBox::Show("Информация о потоке не найдена.");
				error = true;
				return;
			}

			av_dump_format(pFormatCtx, 0, and_SysStringToChar(tbOpenFilePath->Text), 0);

			int i;
			AVCodecContext *pCodecCtxOrig = NULL;
			AVCodecContext *pCodecCtx = NULL;

			// Find the first video stream
			int videoStream = -1;
			for (i = 0; i < pFormatCtx->nb_streams; i++)
			{
				if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
				{
					videoStream = i;
					break;
				}
			}

			if (videoStream == -1)
			{
				MessageBox::Show("Видеопоток не найден.");
				error = true;
				return; // Didn't find a video stream

			}

			pCodecCtx = pFormatCtx->streams[videoStream]->codec;
			double videoFramePerSecond, videoBaseTime, videoDuration;
			// Кадры в секунду.
			videoFramePerSecond = av_q2d(pFormatCtx->streams[videoStream]->r_frame_rate);
			qVideoInfo.push("Количество кадров в секунду = " + round(100 * videoFramePerSecond) / 100);
			worker->ReportProgress(ANYINT);
			// базовая единица времени
			videoBaseTime = av_q2d(pFormatCtx->streams[videoStream]->time_base);
			// длина видео ролика
			videoDuration = (unsigned long)pFormatCtx->streams[videoStream]->duration * (/*videoFramePerSecond **/ videoBaseTime);
			qVideoInfo.push("Длина ролика = " + round(100 * videoDuration) / 100 + "секунд");
			worker->ReportProgress(ANYINT);
			// ширина
			int width = pFormatCtx->streams[videoStream]->codec->width;
			qVideoInfo.push("Ширина изображени = " + width);
			worker->ReportProgress(ANYINT);
			// высота
			int height = pFormatCtx->streams[videoStream]->codec->height;
			qVideoInfo.push("Высота = " + height);
			worker->ReportProgress(ANYINT);


			AVCodec *pCodec = NULL;
			// Find the decoder for the video stream
			pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
			if (pCodec == NULL) {
				MessageBox::Show("Данный кодек не поддерживается.");
				error = true;
				return; // Codec not found
			}

			if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
				MessageBox::Show("Кодек не может быть открыт.");
				error = true;
				return; // Could not open codec
			}

			AVFrame *pFrame = NULL;
			AVFrame *pFrameRGB = NULL;
			// Allocate video frame
			pFrame = av_frame_alloc();
			// Allocate an AVFrame structure
			pFrameRGB = av_frame_alloc();
			if (pFrameRGB == NULL) {
				MessageBox::Show("Кодек не может быть открыт.");
				error = true;
				return;
			}


			uint8_t *buffer = NULL;
			int numBytes;
			//AVPixelFormat PIX_FMT_RGB24;
			// Determine required buffer size and allocate buffer
			numBytes = avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);
			buffer = (uint8_t *)av_malloc(numBytes*sizeof(uint8_t));

			avpicture_fill((AVPicture *)pFrameRGB, buffer, AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);



			struct SwsContext *sws_ctx = NULL;
			int frameFinished;
			AVPacket packet;
			// initialize SWS context for software scaling
			sws_ctx = sws_getContext(pCodecCtx->width,
				pCodecCtx->height,
				pCodecCtx->pix_fmt,
				pCodecCtx->width,
				pCodecCtx->height,
				AV_PIX_FMT_RGB24,
				SWS_BILINEAR,
				NULL,
				NULL,
				NULL
				);

			i = 0;
			bool flag = false;
			clock_t time;
			time = clock();

			while ((av_read_frame(pFormatCtx, &packet) >= 0) && (isWorked)) {
				if (worker->CancellationPending) {
					e->Cancel = true;
					return;
				}
				// Is this a packet from the video stream?
				if (packet.stream_index == videoStream) {
					// Decode video frame
					avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished, &packet);

					// Did we get a video frame?
					if (frameFinished) {
						// Convert the image from its native format to RGB
						sws_scale(sws_ctx, (uint8_t const * const *)pFrame->data,
							pFrame->linesize, 0, pCodecCtx->height,
							pFrameRGB->data, pFrameRGB->linesize);
						if (!flag) {
							flag = true;

							/*
							for (int y = 0; y < 3 * pCodecCtx->width * pCodecCtx->height; ++y) {
								
								if ((y % 3) == 0) {
									*(pFrameRGB->data[0] + y) = 255;
								}
							}
							*/

							SaveDiag(pFrameRGB, pCodecCtx->width, pCodecCtx->height);
							SaveAnalisPix(pFrameRGB, pCodecCtx->width, pCodecCtx->height);
							//SaveSrPix(pFrameRGB, pCodecCtx->width, pCodecCtx->height);
						}
						// Save the frame to disk
						++i;
						if ((0 < i) && (i < 15))
						{
							//++i;
							SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height, i);
							//BMPSave(pFrameRGB, width, height, i);
						}
					}
				}
				av_free_packet(&packet);
				
			}
			clock_t h, m, s, ms;
			time = clock() - time;
			h = time / 3600000;
			time -= h * 3600000;
			m = time / 60000;
			time -= m * 60000;
			s = time / 1000;
			time -= s * 1000;
			ms = time;
			qVideoInfo.push("Время работы: " + h + ":" + m + ":" + s + ":" + ms);
			worker->ReportProgress(ANYINT);


			// Free the RGB image
			av_free(buffer);
			av_free(pFrameRGB);

			// Free the YUV frame
			av_free(pFrame);

			// Close the codecs
			avcodec_close(pCodecCtx);
			avcodec_close(pCodecCtxOrig);

			ppFormatCtx = &pFormatCtx;
			avformat_close_input(ppFormatCtx);

		}
		void backgroundWorker1_RunWorkerCompleted(Object^ /*sender*/, RunWorkerCompletedEventArgs^ e)
		{
			enableUI();
			if (error)
			{
				tbOpenFilePath->Text = String::Empty;
			}
		}

		// This event handler updates the progress bar.
		void backgroundWorker1_ProgressChanged(Object^ /*sender*/, ProgressChangedEventArgs^ e)
		{
			rtbVideoInfo->AppendText(qVideoInfo.front() + "\n");
			qVideoInfo.pop();
			
		}

	private: System::Void btnProcces_Click(System::Object^  sender, System::EventArgs^  e) {
				 isWorked = true;
				 rtbVideoInfo->Text = String::Empty;
				 disableUI();
				 backgroundWorker1->RunWorkerAsync();		 
	}
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			 isWorked = false;
			 pbProccess->Visible = false;
			 rtbVideoInfo->SelectionColor = Color::Red;
			 rtbVideoInfo->AppendText("Процесс анализа прерван!!!\n");
			 rtbVideoInfo->SelectionColor = Color::Gray;

}
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
	}
	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 tbOpenFilePath->Text = openFileDialog1->FileName;
				 }
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 ListViewItem^ item1 = gcnew ListViewItem("item1");
			 item1->SubItems->Add("1");
			 item1->SubItems->Add("2");
			 item1->SubItems->Add("3");

			 ListViewItem^ item2 = gcnew ListViewItem("item2");
			 item2->SubItems->Add("4");
			 item2->SubItems->Add("5");
			 item2->SubItems->Add("6");

			 ListViewItem^ item3 = gcnew ListViewItem("item3");
			 //item3->Checked = true;
			 item3->SubItems->Add("7");
			 item3->SubItems->Add("8");
			 item3->SubItems->Add("9");

			 
			 /*listView1->Columns->Add("Item Column", -2, HorizontalAlignment::Left);
			 listView1->Columns->Add("Column 2", -2, HorizontalAlignment::Left);
			 listView1->Columns->Add("Column 3", -2, HorizontalAlignment::Left);
			 listView1->Columns->Add("Column 4", -2, HorizontalAlignment::Center);		*/	 

			 //array<ListViewItem^>^ temp1 = { item1, item2, item3 };
			 //listView1->Items->AddRange(temp1);
			 lvVideoInfo->Items->Add(item1);

			 //пример взят отсюда->https://msdn.microsoft.com/ru-ru/library/system.windows.forms.listview(v=vs.110).aspx#Примеры
			 //позвони есть что сказать по примеру

			 //ListViewItem^ item0 = gcnew ListViewItem("what", 0);
			 //ListViewItem::ListViewSubItem^ subItems;// = gcnew ListViewItem::ListViewSubItem(item0, "wasdas");// = { gcnew ListViewItem::ListViewSubItem(item0, "qwdasd") };

			 //item0->GetSubItemAt(1, 1);
			 //item0->SubItems->AddRange(subItems);
			 //ListViewItem::ListViewSubItem[] awed;
			
			 //ListViewItem.ListViewSubItem[] subItems;
			 //subItem = item0.
			 //ListViewItem^ item1 = gcnew ListViewItem("who", 1);

			// listView1->Items->Clear();
			 /*item.SubItems();
			 item.;*/

			 //listView1->Items->Add(item0);
			 //listView1->Items->Add(item1);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 lvVideoInfo->Items->Clear();
}
};
}
