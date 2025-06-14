# Timer_Interrupt-Based_Digital_Counter_with_MATLAB_GUI_Monitoring
# Türkçe
Bu proje, Arduino timer interrupt (kesme) sistemi ile çalışan bir dijital sayaç oluşturur ve bu sayacın verileri MATLAB App Designer GUI üzerinden kullanıcıya gerçek zamanlı olarak sunulur.
🧩 Temel Özellikler:
    ⏱️ Arduino tarafında timer1 kesmesiyle periyodik sayaç artışı
    🔁 Sayacın donanımsal butonlarla başlatılması ve sıfırlanması
    🧲 Seri haberleşme ile sayaç değeri MATLAB'e aktarılır
    📊 MATLAB GUI (app11.mlapp) üzerinden anlık sayaç değeri izlenebilir
🛠️ Kullanım:
    timerintlast.ino Arduino’ya yüklenir.
    app11.mlapp MATLAB'de açılır ve doğru seri port seçilir.
    Başlat butonuna tıklanarak sayaç verisi GUI üzerinden izlenmeye başlanır.

# English
This project implements a digital counter using timer interrupts on Arduino, with real-time data monitoring via a MATLAB GUI (App Designer).
🧩 Key Features:
    ⏱️ Counter incremented periodically via timer1 interrupt
    🔘 Manual reset and start via physical buttons on Arduino
    🔁 Serial communication between Arduino and MATLAB
    📊 Real-time counter visualization via app11.mlapp GUI
🛠️ Usage:
    Upload timerintlast.ino to your Arduino board.
    Open app11.mlapp in MATLAB and select the correct COM port.
    Start the GUI to monitor counter values in real-time.
