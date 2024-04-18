object frmDlgCataAlmacen: TfrmDlgCataAlmacen
  Left = 326
  Top = 203
  BorderStyle = bsDialog
  Caption = 'Catalogo de Almacenes'
  ClientHeight = 395
  ClientWidth = 328
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object dxDBGrid1: TdxDBGrid
    Left = 7
    Top = 9
    Width = 314
    Height = 344
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CLAVE'
    SummaryGroups = <>
    SummarySeparator = ', '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnDblClick = btnAceptarClick
    BandFont.Charset = DEFAULT_CHARSET
    BandFont.Color = clWindowText
    BandFont.Height = -11
    BandFont.Name = 'MS Sans Serif'
    BandFont.Style = []
    DataSource = dtsAlmacen
    Filter.Criteria = {00000000}
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clWindowText
    HeaderFont.Height = -11
    HeaderFont.Name = 'MS Sans Serif'
    HeaderFont.Style = []
    LookAndFeel = lfUltraFlat
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
    OptionsView = [edgoBandHeaderWidth, edgoIndicator, edgoRowSelect, edgoUseBitmap]
    PreviewFont.Charset = DEFAULT_CHARSET
    PreviewFont.Color = clBlue
    PreviewFont.Height = -11
    PreviewFont.Name = 'MS Sans Serif'
    PreviewFont.Style = []
    object dxDBGrid1CLAVE: TdxDBGridMaskColumn
      Alignment = taCenter
      Caption = 'Clave'
      Width = 55
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CLAVE'
    end
    object dxDBGrid1NOMBRE: TdxDBGridMaskColumn
      Caption = 'Descripción del Almacén'
      Width = 214
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE'
    end
  end
  object btnAceptar: TBitBtn
    Left = 136
    Top = 361
    Width = 80
    Height = 30
    Caption = '&Aceptar'
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = btnAceptarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      66666666666666666666666666666666666666666666666666666666AC666666
      66666666F86666666666666A22C666666666666F88866666666666A2222C6666
      666666F88888666666666A222222C66666666F888888866666666A22CA222C66
      66666F888F88886666666A2C66A222C666666F8866F8888666666AC6666A222C
      66666F86666F8888666666666666A222C66666666666F8888666666666666A22
      2C66666666666F8888666666666666A222C66666666666F8888666666666666A
      22C666666666666F8886666666666666A2C6666666666666F886666666666666
      6AC66666666666666F8666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object btnCerrar: TBitBtn
    Left = 240
    Top = 361
    Width = 80
    Height = 30
    Caption = '&Cerrar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = btnCerrarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      6666666666666666666666666666666666666666666666666666666666666666
      6666666666666666666669000666669000666F88866666F88866691110666911
      10666F8888666F888866669111069111066666F88886F8888666666911101110
      6666666F88888888666666669111110666666666F88888866666666669111066
      666666666F888866666666669111110666666666F88888866666666911101110
      6666666F888888886666669111069111066666F88886F8888666691110666911
      10666F8888666F88886669999666669999666FFFF66666FFFF66666666666666
      6666666666666666666666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object qsAlmancen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from almacen where cia = :Cia order by clav' +
        'e')
    Left = 136
    Top = 80
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsAlmacen: TDataSource
    DataSet = qsAlmancen
    Left = 136
    Top = 120
  end
end
