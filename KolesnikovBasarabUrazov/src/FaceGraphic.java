
package ru.nnesterov.smiley;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.content.Context;
import android.graphics.drawable.BitmapDrawable;
import android.os.Environment;
import android.view.View;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.os.Bundle;
import android.view.View;
import com.google.android.gms.vision.face.Face;
import ru.nnesterov.smiley.FaceTrackerActivity;

import java.io.File;
import java.util.List;

import ru.nnesterov.smiley.ui.camera.GraphicOverlay;

class FaceGraphic extends GraphicOverlay.Graphic {
    private static final float ID_TEXT_SIZE = 60.0f;
    private static final float BOX_STROKE_WIDTH = 5.0f;

    private static final int VALID_COLOR = Color.GREEN;
    private static final int INVALID_COLOR = Color.RED;

    private Paint mPaint;
    private String PathBeard;
    private volatile Face mFace;
    private int mFaceId;
    private boolean mIsReady = false;
    private final String mNotReadyMessage;
    private final String mReadyMessage;

    FaceGraphic(GraphicOverlay overlay) {
        super(overlay);
        // PathBeard=path;
        mNotReadyMessage = overlay.getContext().getResources().getString(R.string.not_ready_message);
        mReadyMessage = overlay.getContext().getResources().getString(R.string.ready_message);
        mPaint = new Paint();
        mPaint.setColor(VALID_COLOR);
        mPaint.setStyle(Paint.Style.STROKE);
        mPaint.setStrokeWidth(BOX_STROKE_WIDTH);
        mPaint.setTextSize(ID_TEXT_SIZE);
    }

    public void setPathBeard(String pathBeard) {
        PathBeard = pathBeard;
    }

    void setId(int id) {
        mFaceId = id;
    }


    void setIsReady(boolean isValid) {
        this.mIsReady = isValid;
        mPaint.setColor(isValid ? VALID_COLOR : INVALID_COLOR);
    }


    /**
     * Обновляет экземпляр лица от обнаружения последнего кадра.
     * Соответствующие части наложения, чтобы вызвать перерисовку.
     */
    void updateFace(Face face) {
        mFace = face;
        postInvalidate();
    }

    /**
     * Рисует аннотации лица для позиции на холсте.
     */
    @Override
    public void draw(Canvas canvas) {
        Face face = mFace;
        if (face == null) {
            return;
        }
        FaceTrackerActivity path = new FaceTrackerActivity();

        File helmet = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS), "untitled.png");
        File beard = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS), PathBeard != "" ? PathBeard : "ber2.png");
        Bitmap mBitmap = BitmapFactory.decodeFile(helmet.getAbsolutePath());

        Bitmap mBitmapBeard = BitmapFactory.decodeFile(beard.getAbsolutePath());
        float x = translateX(face.getPosition().x + face.getWidth() / 2);
        float y = translateY(face.getPosition().y + face.getHeight() / 2);


        // Рисует рамку вокруг лица.
        float xOffset = scaleX(face.getWidth() / 2.0f);
        float yOffset = scaleY(face.getHeight() / 2.0f);

        int WidthMask = (int) face.getWidth() * 2;
        int HeightMask = (int) (face.getHeight() * 1.5f);
        Bitmap HelmetBitmap = Bitmap.createScaledBitmap(mBitmap, WidthMask, HeightMask, false);
        Bitmap newBitmapBeard = Bitmap.createScaledBitmap(mBitmapBeard, WidthMask, HeightMask, false);
        float left = x - xOffset;
        float top = y - yOffset;
        float right = x + xOffset;
        float bottom = y + yOffset;
        Object[] L = new Object[100];

        canvas.drawBitmap(HelmetBitmap, left + 15, top, mPaint);// Накладываем шлем
        canvas.drawBitmap(newBitmapBeard, left, (bottom - HeightMask / 1.5f), mPaint);//Накладываем бороду

    }
}