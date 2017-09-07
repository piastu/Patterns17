package ru.nnesterov.smiley;

import android.Manifest;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Camera;
import android.graphics.Color;
import android.location.LocationManager;
import android.net.Uri;
import android.os.Bundle;

import android.support.design.widget.Snackbar;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GoogleApiAvailability;
import com.google.android.gms.vision.CameraSource;
import com.google.android.gms.vision.MultiProcessor;
import com.google.android.gms.vision.Tracker;
import com.google.android.gms.vision.face.Face;
import com.google.android.gms.vision.face.FaceDetector;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import ru.nnesterov.smiley.ui.camera.CameraSourcePreview;
import ru.nnesterov.smiley.ui.camera.GraphicOverlay;


/**
 * Активность для приложения face tracker. Это приложение обнаруживает лица с камерой заднего вида и рисует
 *  * Наложить графику, чтобы указать положение, размер и идентификатор каждой грани.
 */
public final class FaceTrackerActivity extends AppCompatActivity {
    private static final String TAG = "FaceTracker";
    public String FILE = "";
    private CameraSource mCameraSource = null;
     private int Camera_Back_or_Front=CameraSource.CAMERA_FACING_FRONT;

    private CameraSourcePreview mPreview;
    private GraphicOverlay mGraphicOverlay;

    private static final int RC_HANDLE_GMS = 9001;
    // коды запросов на получение разрешений должны быть < 256
    private static final int RC_HANDLE_CAMERA_PERM = 2;

    //==============================================================================================
    // Activity Methods
    //==============================================================================================

    /**
     * Инициализирует пользовательский интерфейс и инициирует создание детектора лица.
     */

    private List<Beard> beards;
    private RecyclerView rv;
    private RVAdapter mAdapter;

    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        setContentView(R.layout.main);

        mPreview = (CameraSourcePreview) findViewById(R.id.preview);
        mGraphicOverlay = (GraphicOverlay) findViewById(R.id.faceOverlay);

        // Проверяем разрешение камеры перед доступом к камере. Если
        // разрешение еще не предоставлено, разрешение на запрос.
        int rc = ActivityCompat.checkSelfPermission(this, Manifest.permission.CAMERA);
        if (rc == PackageManager.PERMISSION_GRANTED) {
            createCameraSource(Camera_Back_or_Front);
        } else {
            requestCameraPermission();
        }

        //==============================================================================================
        // RececlerView добавление карточек
        //==============================================================================================
        rv = (RecyclerView) findViewById(R.id.rv);

        LinearLayoutManager llm = new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false);
        rv.setLayoutManager(llm);
        rv.setHasFixedSize(true);
        rv.setItemAnimator(new DefaultItemAnimator());
        rv.setAdapter(mAdapter);
        rv.addOnItemTouchListener(new RecyclerTouchListener(getApplicationContext(), rv, new RecyclerTouchListener.ClickListener() {
            @Override
            public void onClick(View view, int position) {
                Beard beard = beards.get(position);
                Toast toast = Toast.makeText(getApplicationContext(),
                        "Выбрано: " + beard.getName(), Toast.LENGTH_SHORT);
                toast.show();
                FILE = beard.getAge();
            }

            @Override
            public void onLongClick(View view, int position) {

            }
        }));
        initializeData();
        initializeAdapter();
    }

    private void initializeData() {
        beards = new ArrayList<>();
        File mFile = new File("/storage/emulated/0/Download/");

        String[] mFiles = mFile.list(new FilenameFilter() {

            @Override
            public boolean accept(File folder, String name) {
                return name.endsWith(".png");
            }

        });

        for (int i = 0; i < mFiles.length; i++) {
            beards.add(new Beard("Борода№" + (i + 1), mFiles[i], R.drawable.emma));
        }
    }

    private void initializeAdapter() {
        RVAdapter adapter = new RVAdapter(beards);
        rv.setAdapter(adapter);
    }

    private void requestCameraPermission() {
        final String[] permissions = new String[]{Manifest.permission.CAMERA};

        if (!ActivityCompat.shouldShowRequestPermissionRationale(this,
                Manifest.permission.CAMERA)) {
            ActivityCompat.requestPermissions(this, permissions, RC_HANDLE_CAMERA_PERM);
            return;
        }

        final Activity thisActivity = this;

        View.OnClickListener listener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ActivityCompat.requestPermissions(thisActivity, permissions,
                        RC_HANDLE_CAMERA_PERM);
            }
        };

        Snackbar.make(mGraphicOverlay, R.string.permission_camera_rationale,
                Snackbar.LENGTH_INDEFINITE)
                .setAction(R.string.ok, listener)
                .show();
    }

    /**
     * Создает и запускает камеру
     */
    private void createCameraSource(int camera_Back_or_Front) {

        Context context = getApplicationContext();
        FaceDetector detector = new FaceDetector.Builder(context)
                // Включаем расчет для глаз и улыбки
                .setClassificationType(FaceDetector.ALL_CLASSIFICATIONS)
                // Только "главное" лицо в кадре
                .setProminentFaceOnly(true)
                .build();

        detector.setProcessor(
                new MultiProcessor.Builder<>(new GraphicFaceTrackerFactory())
                        .build());

        if (!detector.isOperational()) {

            Log.w(TAG, "Зависимости детоктора лиц не активны");
        }

        mCameraSource = new CameraSource.Builder(context, detector)
                .setRequestedPreviewSize(640, 480)
                .setFacing(camera_Back_or_Front)
                .setRequestedFps(30.0f)
                .build();
    }

    /**
     * Рестарт камеры.
     */
    @Override
    protected void onResume() {
        super.onResume();

        startCameraSource();
    }

    /**
     * Остановка камеры.
     */
    @Override
    protected void onPause() {
        super.onPause();
        mPreview.stop();
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (mCameraSource != null) {
            mCameraSource.release();
        }
    }



    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        if (requestCode != RC_HANDLE_CAMERA_PERM) {
            Log.d(TAG, "Получили неожиданный результа: " + requestCode);
            super.onRequestPermissionsResult(requestCode, permissions, grantResults);
            return;
        }

        if (grantResults.length != 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            createCameraSource(Camera_Back_or_Front);
            return;
        }

        DialogInterface.OnClickListener listener = new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                finish();
            }
        };

        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Face Tracker sample")
                .setMessage(R.string.no_camera_permission)
                .setPositiveButton(R.string.ok, listener)
                .show();
    }

    /**
     * Запускает или перезапускает источник камеры, если он существует. Если источник камеры еще не существует
     *      * (Например, поскольку onResume был вызван до создания источника камеры), это будет вызвано
     *      * Снова при создании источника камеры.
     */
    private void startCameraSource() {

        // проверить, что устройство имеет игровые сервисы.
        int code = GoogleApiAvailability.getInstance().isGooglePlayServicesAvailable(
                getApplicationContext());
        if (code != ConnectionResult.SUCCESS) {
            Dialog dlg =
                    GoogleApiAvailability.getInstance().getErrorDialog(this, code, RC_HANDLE_GMS);
            dlg.show();
        }

        if (mCameraSource != null) {
            try {
                mPreview.start(mCameraSource, mGraphicOverlay);
            } catch (IOException e) {
                mCameraSource.release();
                mCameraSource = null;
            }
        }
    }

    private void takeShot() {
        mCameraSource.takePicture(null, new CameraSource.PictureCallback() {
            @Override
            public void onPictureTaken(byte[] bytes) {
                mPreview.stop();
                File shot = null;
                try {
                    shot = FileUtils.saveImage(bytes, "jpg");
                } catch (IOException e) {
                    e.printStackTrace();
                    return;
                }
                Intent shareIntent = new Intent(Intent.ACTION_SEND);
                shareIntent.setType("image/jpeg");
                shareIntent.putExtra(Intent.EXTRA_STREAM, Uri.fromFile(shot));
                startActivity(Intent.createChooser(shareIntent, ""));
            }
        });
    }

    //==============================================================================================
    // Графический Face Tracker
    //==============================================================================================

    /**
     * Фабрика для создания лицевого трекера, связанного с новым лицом
     */
    private class GraphicFaceTrackerFactory implements MultiProcessor.Factory<Face> {
        @Override
        public Tracker<Face> create(Face face) {
            return new GraphicFaceTracker(mGraphicOverlay, FILE);
        }
    }

    /**
     * Face tracker для каждого обнаруженного человека.
     */

    private class GraphicFaceTracker extends Tracker<Face> {
        private static final double SMILING_THRESHOLD = 0.4; // Значение-Улыбка
        private static final double WINK_THRESHOLD = 0.5; // вероятность подмигивания
        private GraphicOverlay mOverlay;
        private FaceGraphic mFaceGraphic;
        private String PAth;

        GraphicFaceTracker(GraphicOverlay overlay, String path) {
            mOverlay = overlay;
            PAth = path;
            mFaceGraphic = new FaceGraphic(overlay);
        }

        /**
         * Отслеживание лица
         */
        @Override
        public void onNewItem(int faceId, Face item) {
            mFaceGraphic.setId(faceId);
        }

        /**
         * Обновление положения лица
         */
        @Override
        public void onUpdate(FaceDetector.Detections<Face> detectionResults, Face face) {
            mOverlay.add(mFaceGraphic);
            mFaceGraphic.setPathBeard(PAth);
            boolean isSmiling = face.getIsSmilingProbability() > SMILING_THRESHOLD;//
            if (isSmiling) {
                float leftEye = face.getIsLeftEyeOpenProbability();
                float rightEye = face.getIsRightEyeOpenProbability();
                if (Math.abs(leftEye - rightEye) >= WINK_THRESHOLD) {
                    takeShot();
                }
            }

            mFaceGraphic.setIsReady(isSmiling);
            mFaceGraphic.updateFace(face);
        }

        /**
         * Скрыть графику, если соответствующее лицо не было обнаружено.
         */
        @Override
        public void onMissing(FaceDetector.Detections<Face> detectionResults) {
            mOverlay.remove(mFaceGraphic);
        }

        /**
         * Удаляем графическую анотацию
         */
        @Override
        public void onDone() {
            mOverlay.remove(mFaceGraphic);
        }

    }

    @Override
    protected void onStart() {
        super.onStart();

        LocationManager locationManager =
                (LocationManager) getSystemService(Context.LOCATION_SERVICE);
        boolean gpsEnabled = locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER);

        if (!gpsEnabled) {

        }
    }

    @Override
    protected void onRestart() {
        super.onRestart();
    }
}
